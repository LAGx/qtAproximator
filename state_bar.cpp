#include "state_bar.h"




StateBar::StateBar(IAplicationManager *_aplicationManager, QWidget *_parentWidget, const AproximatorStyle& _style):
    aplicationManager(_aplicationManager), parentWidget(_parentWidget), style(_style){

    stateButton = new QPushButton("RUN!", parentWidget);
    QObject::connect(stateButton, SIGNAL (released()),this, SLOT (on_released_stateButton()));
    QObject::connect(stateButton, SIGNAL (pressed()),this, SLOT (on_pressed_stateButton()));

    langrange_info = new QWidget(parentWidget);
    lsm_info = new QWidget(parentWidget);
    langrange_text = new QLabel("Interpolation\npolynomial of\n    Lagrange", langrange_info);
    lsm_text = new QLabel("         Least \nsquare method\nError: \n\n> ", lsm_info);

    updateLayout();
}



void StateBar::updateLayout(){

    langrange_info->setStyleSheet("border:2px solid "+  style.langrangePlotColor.name() +";");
    lsm_info->setStyleSheet("border:2px solid "+  style.lsmPlotColor.name() +";");

    langrange_info->setGeometry(QRect(QPoint(parentWidget->width()*10/100, parentWidget->width()*10/100),
                                      QSize(parentWidget->width()*80/100, (parentWidget->height()-parentWidget->width())/2 - parentWidget->width()*10/100)));

    lsm_info->setGeometry(QRect(QPoint(parentWidget->width()*10/100, parentWidget->width()*20/100+ langrange_info->height()),
                                QSize(parentWidget->width()*80/100, (parentWidget->height()-parentWidget->width())/2 - parentWidget->width()*10/100)));

    stateButton->setGeometry( QRect( QPoint((parentWidget->width() - (parentWidget->width() - 2*parentWidget->width()*15/100))/2,
                                            parentWidget->height() - parentWidget->width()*15/100 - (parentWidget->width() - 2*parentWidget->width()*15/100)),
                                     QSize(parentWidget->width() - 2*parentWidget->width()*15/100,
                                           parentWidget->width() - 2*parentWidget->width()*15/100)));

    stateButton->setStyleSheet("background: "+  style.baseMajorColor.name() +";"
                               "color: "+  style.baseMinorColor.name() +";"
                               "border:2px solid "+  style.baseMinorColor.name() +";"
                               "font-size: "+QString::number(stateButton->height()*18/100)+ "px;"
                               );

    langrange_text->setStyleSheet("color:" + style.textMainColor.name() + ";"
                                  "border:0px solid "+  style.baseMinorColor.name() +";"
                                  "font-size: " + QString::number(langrange_info->width()*10/100)+"px;"
                                  );

    lsm_text->setStyleSheet("color:" + style.textMainColor.name() + ";"
                            "border:0px solid "+  style.baseMinorColor.name() +";"
                            "font-size: " + QString::number(langrange_info->width()*10/100)+"px;"
                                  );

    langrange_text->setGeometry(QRect(
                          QPoint(langrange_info->width()/5, 0),
                          QSize(langrange_info->width(), langrange_info->height())
                     ));

    lsm_text->setGeometry(QRect(
                          QPoint(langrange_info->width()/5, 0),
                          QSize(langrange_info->width(), langrange_info->height())
                     ));

}



void StateBar::on_pressed_stateButton(){
    stateButton->setStyleSheet("background: "+  style.buttonPressedOnColor.name() +";"
                               "color: "+  style.baseMinorColor.name() +";"
                               "border:2px solid "+  style.baseMinorColor.name() +";"
                               "font-size: "+QString::number(stateButton->height()*18/100)+ "px;"
                               );
}


void StateBar::on_released_stateButton(){

    stateButton->setStyleSheet("background: "+  style.buttonPressedOnColor.name() +";"
                               "color: "+  style.baseMinorColor.name() +";"
                               "border:2px solid "+  style.baseMinorColor.name() +";"
                               "font-size: "+QString::number(stateButton->height()*18/100)+ "px;"
                               );

    stateButton->setEnabled(false);
    stateButton->setText("calc...");

    aplicationManager->plotResult();

    stateButton->setText("RUN!");
    stateButton->setEnabled(true);

    stateButton->setStyleSheet("background: "+  style.baseMajorColor.name() +";"
                               "color: "+  style.baseMinorColor.name() +";"
                               "border:2px solid "+  style.baseMinorColor.name() +";"
                               "font-size: "+QString::number(stateButton->height()*18/100)+ "px;"
                               );
}


void StateBar::setLSMerror(double error){

    lsm_text->setText("         Least \nsquare method\nError: \n\n> " +
                      QString::number(error).mid(0,11));
}
