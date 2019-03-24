#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include "PortAudioWrapper.h"


#define VERSION_OF_APP "1.0"
#define MY_APP_NAME "Audio Aucoustic Analyzer"




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

private:
    Ui::MainWindow *ui;
    DevicesInfoDialog *devicesWidget;
    PortAudioWrapper myPortAudioWrapper;
};


#endif // MAINWINDOW_H
