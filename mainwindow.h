#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>
#include "aplication_manager.h"

namespace Ui{
    class MainWindow;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:

    Ui::MainWindow *ui;
    std::unique_ptr<AplicationManager> aplicationManager;


    void resizeEvent(QResizeEvent *event);
    void showEvent(QShowEvent *event);

    AplicationManager::SetSettingsInfo settings;

    QPushButton* button;
    QCustomPlot* custumPlot;

};

#endif // MAINWINDOW_H
