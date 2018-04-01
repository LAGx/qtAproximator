#include "plotter.h"
#include <iostream>

Plotter::Plotter(QWidget* _parentWidget, const AproximatorStyle& _style): parentWidget(_parentWidget), style(_style){
    customPlot = new QCustomPlot(_parentWidget);

    // set some pens, brushes and backgrounds:
    customPlot->xAxis->setBasePen(QPen(style.baseMinorColor, 2));
    customPlot->yAxis->setBasePen(QPen(style.baseMinorColor, 2));
    customPlot->xAxis->setTickPen(QPen(style.baseMinorColor, 2));
    customPlot->yAxis->setTickPen(QPen(style.baseMinorColor, 2));
    customPlot->xAxis->setSubTickPen(QPen(style.baseMinorColor, 2));
    customPlot->yAxis->setSubTickPen(QPen(style.baseMinorColor, 2));

    customPlot->xAxis->setTickLabelColor(style.baseMinorColor);
    customPlot->yAxis->setTickLabelColor(style.baseMinorColor);

    customPlot->xAxis->grid()->setPen(QPen(style.buttonPressedOnColor, 1, Qt::DashLine));
    customPlot->yAxis->grid()->setPen(QPen(style.buttonPressedOnColor, 1, Qt::DashLine));

    customPlot->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    customPlot->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    customPlot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    customPlot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);

    QLinearGradient plotGradient;
    plotGradient.setColorAt(0, style.baseMajorColor);
    customPlot->setBackground(plotGradient);
}



void Plotter::setNewSettings(const SetSettingsInfo info){

    stepsGraphsResolution =info.stepsGraphsResolution;

    customPlot->setGeometry(parentWidget->geometry());

    customPlot->xAxis->setRange(info.graphRangeX.x(), info.graphRangeX.y());
    customPlot->yAxis->setRange(info.graphRangeY.x(), info.graphRangeY.y());

    customPlot->replot();
    recreateSliders(info);
}


void Plotter::recreateSliders(const SetSettingsInfo& info){

    need_sliders = info.slidersRange.y() - info.slidersRange.x()+1;
    graphRangeY = info.graphRangeY;
    graphRangeX = info.graphRangeX;

    for(auto slider: sliders)
        slider->setVisible(false);

    while(sliders.size()<need_sliders)
        sliders.push_back(new QSlider(Qt::Vertical,customPlot));

    int i = 0;
    for(int cord = info.slidersRange.x(); i < need_sliders; cord++, i++){


        sliders[i]->setGeometry(QRect(QPoint(0, 0), QSize(sliders[i]->geometry().width(), (customPlot->yAxis->coordToPixel(0)-customPlot->yAxis->coordToPixel(1)) * (info.graphRangeY.y()-info.graphRangeY.x()))));

        QRect geo = sliders[i]->geometry();
        geo.moveCenter(QPoint(customPlot->xAxis->coordToPixel(cord)-15, customPlot->yAxis->coordToPixel(((double)info.graphRangeY.y()-(double)info.graphRangeY.x())/2)));
        sliders[i]->setGeometry(geo);

        sliders[i]->setRange(0, 99);
        sliders[i]->setValue(50);

        sliders[i]->setStyleSheet("background-color: #00000000;");

        sliders[i]->setVisible(true);
    }

}


void Plotter::drawGraph(IGraph* graph){
    QCPGraph *plot_gr = customPlot->addGraph();

    QVector<double> x(stepsGraphsResolution);
    QVector<double> y(x.size());

    double step = customPlot->xAxis->range().size()/stepsGraphsResolution;
    int i = 0;

    for(double way = customPlot->xAxis->range().lower ;way < customPlot->xAxis->range().upper && i < x.size();way+=step, i++)
        x[i] = way;

    for(int i = 0; i < x.size(); i++)
        y[i] = (*graph)(x[i]);

    plot_gr->setData(x, y);

    switch(graph->getType()){
        case LANGRANGE:
            plot_gr->setPen(QPen(style.langrangePlotColor, 2.5));
            break;
        case LSM:
            plot_gr->setPen(QPen(style.lsmPlotColor, 2.5));
            break;
        default:
            plot_gr->setPen(QPen(style.defaultPlotColor, 2.5));
    }

    allGraphs.push_back(plot_gr);

    customPlot->replot();
}


void Plotter::clearPlot(){
    for(QCPGraph* el: allGraphs)
        customPlot->removeGraph(el);
    allGraphs.clear();

    customPlot->replot();
}


QVector<QPointF> Plotter::getUserPoints(){
    QVector<QPointF> vec;

    for(int i = 0; i < need_sliders; i++)
        vec.push_back(QPointF(-graphRangeX.x() + i, ((double)sliders[i]->value()/100*(graphRangeY.y()-graphRangeY.x())+graphRangeY.x())));

    return vec;
}
