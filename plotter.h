#ifndef PLOTTER_H
#define PLOTTER_H
#include <QVector>
#include <QSlider>


#include "qcustomplot.h"
#include "aproximator_style.h"
#include "graph_interface.h"



class Plotter: public QObject{

Q_OBJECT

public:

    struct SetSettingsInfo{

        SetSettingsInfo(const QPoint& _graphRangeX, const QPoint& _graphRangeY, const QPoint& _slidersRange):
            graphRangeX(_graphRangeX), graphRangeY(_graphRangeY), slidersRange(_slidersRange)
            {}

        QPoint graphRangeX = {-1, 7}; //by x
        QPoint graphRangeY = {0,1}; //by y
        QPoint slidersRange = {1,5}; //range settings sliders
        int stepsGraphsResolution = 350;
    };


    Plotter(QWidget* parentWidget, const AproximatorStyle& style);

    void setNewSettings(const SetSettingsInfo info);

    void drawGraph(IGraph*);

    void clearPlot();

    QVector<QPointF> getUserPoints();

private:

    QVector<QCPGraph*> allGraphs;

    void recreateSliders(const SetSettingsInfo& info);

    int stepsGraphsResolution = 3;

    AproximatorStyle style;

    QWidget* parentWidget;

    QCustomPlot* customPlot;

    QVector<QSlider*> sliders;
    int need_sliders = 0;
    QPoint graphRangeY;
    QPoint graphRangeX;
};





#endif // PLOTTER_H
