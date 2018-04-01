#ifndef STATE_BAR_H
#define STATE_BAR_H
#include <QPushButton>
#include <QLabel>

#include "aplication_interface.h"
#include "aproximator_style.h"


class StateBar: public QObject{

Q_OBJECT

public:

    StateBar(IAplicationManager* _aplicationManager, QWidget* _parentWidget, const AproximatorStyle& style);

    void updateLayout();

    void setLSMerror(double error);

private:

    AproximatorStyle style;

    QPushButton* stateButton;

    QWidget* parentWidget;

    IAplicationManager* aplicationManager;

    QWidget* langrange_info;
    QWidget* lsm_info;
    QLabel* langrange_text;
    QLabel* lsm_text;

private slots:

    void on_released_stateButton();

    void on_pressed_stateButton();

};






#endif // STATE_BAR_H
