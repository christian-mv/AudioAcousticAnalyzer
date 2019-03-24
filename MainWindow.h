#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include "PortAudioWrapper.h"
#include <QtCharts>

#define VERSION_OF_APP "1.0"
#define MY_APP_NAME "Audio Aucoustic Analyzer"


using namespace QtCharts;


class DevicesInfoDialog;


namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionDevices_triggered();

    void on_actionRecord_triggered();

    void on_actionPlay_triggered();

    void on_actionPlot_triggered();

    void plot();


private:
    Ui::MainWindow *ui;
    DevicesInfoDialog *devicesWidget;
    PortAudioWrapper myPortAudioWrapper;
    QLineSeries *series;
};


#endif // MAINWINDOW_H
