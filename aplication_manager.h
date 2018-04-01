#ifndef APLICATION_MANAGER_H
#define APLICATION_MANAGER_H
#include <QMainWindow>
#include <QSize>
#include <QFrame>
#include <QWidget>
#include <memory>
#include "langrange.h"
#include "least_square_method.h"
#include "plotter.h"
#include "state_bar.h"
#include "aplication_interface.h"
#include "aproximator_style.h"


class AplicationManager: public IAplicationManager{
public:

    struct SetSettingsInfo{
        QSize windowSize;
        QPoint ratioPlotToStateBar = {80, 20}; //< how much will fill plot and state bar on screen (x+y = 100)
        QPoint graphRangeX = {-1, 7}; //by x
        QPoint graphRangeY = {0,1}; //by y
        QPoint slidersRange = {1,5}; //range settings sliders {1, 2, 3, 4, 5}
    };

    AplicationManager(QWidget* _parentWindow, AproximatorStyle style = AproximatorStyle());

    void setNewSettings(const SetSettingsInfo info);

private:

    AproximatorStyle style;

    void plotResult();

    QWidget* parentWindow; //OK

    Langrange langrange;
    LeastSquareMethod_3pow lsm;

    QFrame* plotFrame;
    QFrame* stateBarFrame;

    std::unique_ptr<Plotter> plotter;
    std::unique_ptr<StateBar> stateBar;

};


#endif // APLICATION_MANAGER_H
