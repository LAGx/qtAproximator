#include "aplication_manager.h"
#include <iostream>

AplicationManager::AplicationManager(QWidget* _parentWindow, AproximatorStyle _style):
    parentWindow(_parentWindow), style(_style){

    AplicationManager::SetSettingsInfo info;
    info.windowSize = parentWindow->size();

    plotFrame = new QFrame(parentWindow);
    stateBarFrame = new QFrame(parentWindow);


    stateBarFrame->setObjectName("myObject");
    stateBarFrame->setStyleSheet("#myObject { border: 2px solid "+style.baseMinorColor.name()+";"
                                            " background-color: "+style.baseMajorColor.name()+"; }");

    plotFrame->setObjectName("myObject");
    plotFrame->setStyleSheet("#myObject { background-color: "+style.baseMajorColor.name()+"; }");


    plotter.reset(new Plotter(plotFrame, style));
    stateBar.reset(new StateBar(this, stateBarFrame, style));

    this->setNewSettings(info);
    plotResult();
}




void AplicationManager::setNewSettings(const SetSettingsInfo info){

    plotFrame->setGeometry(QRect(QPoint(0,0),
                                  QSize(info.windowSize.width()*info.ratioPlotToStateBar.x()/100, info.windowSize.height())));
    stateBarFrame->setGeometry(QRect(QPoint(info.windowSize.width()*info.ratioPlotToStateBar.x()/100, 0),
                                      QSize(info.windowSize.width()*info.ratioPlotToStateBar.y()/100,info.windowSize.height())));

    plotter->setNewSettings(Plotter::SetSettingsInfo(info.graphRangeX, info.graphRangeY, info.slidersRange));
    stateBar->updateLayout();
}



void AplicationManager::plotResult(){

    langrange.changeState(plotter->getUserPoints());
    lsm.changeState(plotter->getUserPoints());

    stateBar->setLSMerror(lsm.getError());

    plotter->clearPlot();
    plotter->drawGraph(&langrange);
    plotter->drawGraph(&lsm);

}
