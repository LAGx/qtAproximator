#ifndef APLICATION_MANAGER_H
#define APLICATION_MANAGER_H
#include <QMainWindow>
#include <QSize>
#include "langrange.h"
#include "least_square_method.h"
#include "plotter.h"
#include "state_bar.h"
#include "mainwindow.h"
#include <QFrame>
#include <QWidget>

class IAplicationManager{
public:

    virtual void plotResult() = 0;

    virtual void changeSizeXAxis(double newSize) {} // gives opportunity change axes range
    virtual void changeSizeYAxis(double newSize) {} // gives opportunity change axes range
};


class AplicationManager: public IAplicationManager{
public:

    struct SetSettingsInfo{
        QSize windowSize;
        QPoint ratioPlotToStateBar = {80, 20}; //< how much will fill plot and state bar on screen (x+y = 100)
        QPoint graphRange[2] = {{0, 7},{0,1}}; //by x and y
    };

    AplicationManager(QWidget* _parentWindow){} //TODO

    void setNewSettings(const SetSettingsInfo info){} //TODO

private:

    void plotResult(){} //TODO

    QWidget* _parentWindow;

    //Langrange langrange;
    //LeastSquareMethod lsm;

    QFrame* plotFrame;
    QFrame* stateBarFrame;

    //unique_ptr<Plotter> plotter;
    //unique_ptr<StateBar> stateBar;

};


#endif // APLICATION_MANAGER_H
