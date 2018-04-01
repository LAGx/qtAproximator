#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopWidget>
#include <cmath>
#include <QDebug>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);


    resize(QDesktopWidget().availableGeometry(this).size() );

    aplicationManager.reset(new AplicationManager(this));

}


void MainWindow::resizeEvent(QResizeEvent *event){

    settings.windowSize = this->size();

    aplicationManager->setNewSettings(settings);

    QMainWindow::resizeEvent(event);
}


void MainWindow::showEvent(QShowEvent *event){

    settings.windowSize = this->size();

    aplicationManager->setNewSettings(settings);

    QMainWindow::showEvent(event);
}


MainWindow::~MainWindow(){
    delete ui;
}

    /*
    button = new QPushButton("hello world", ui->customPlot);
    moveButtonFromCoord();


   //ui->customPlot->setGeometry(QRect(QPoint(0,0), QSize(this->width()*0.8, this->height())));

    slider = new QSlider(Qt::Vertical, this);



    makePlot();


    //slider->setGeometry(QRect(
    //                        QPoint(ui->customPlot->xAxis->coordToPixel(0) - slider->width()/2,ui->customPlot->xAxis->coordToPixel(1)),
    //                        QSize(slider->width(),std::abs(ui->customPlot->yAxis->coordToPixel(0) - ui->customPlot->yAxis->coordToPixel(1)))
    //                        ));
}



MainWindow::~MainWindow()
{
    delete ui;
}



/*

void MainWindow::moveButtonFromCoord()
{

    double real_x = ui->customPlot->xAxis->coordToPixel(0);
    double real_y = ui->customPlot->yAxis->coordToPixel(0);
    QRect geo = button->geometry();
    geo.moveCenter(QPoint(real_x, real_y));
    button->setGeometry(geo);
}


void MainWindow::resizeEvent(QResizeEvent *event)
{
    //moveButtonFromCoord();
    QMainWindow::resizeEvent(event);
}

void MainWindow::showEvent(QShowEvent *event)
{
    moveButtonFromCoord();
    QMainWindow::showEvent(event);
}


void MainWindow::makePlot(){
    // generate some data:
    QVector<double> x(101), y(101); // initialize with entries 0..100
    for (int i=0; i<101; ++i)
    {
      x[i] = i/50.0 - 1; // x goes from -1 to 1
      y[i] = x[i]*x[i]; // let's plot a quadratic function
    }
    // create graph and assign data to it:
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x, y);
    // give the axes some labels:
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->customPlot->xAxis->setRange(-1, 1);
    ui->customPlot->yAxis->setRange(0, 1);
    ui->customPlot->replot();



   //double real_x = ui->customPlot->xAxis->coordToPixel(0)+ui->customPlot->x();
   //double real_y = ui->customPlot->yAxis->coordToPixel(0)+ui->customPlot->y();

   //QPoint real_cord(real_x, real_y);

   //button->setGeometry(QRect(real_cord, QSize(20,20)));

   //button->move(real_cord);


}

*/
