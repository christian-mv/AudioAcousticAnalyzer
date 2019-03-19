#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "DevicesInfoDialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionDevices_triggered()
{
    devicesWidget = new DevicesInfoDialog(this, myPortAudioWrapper);

    devicesWidget->setWindowTitle( tr(" Audio Devices - "
                                MY_APP_NAME " V" VERSION_OF_APP ));

    devicesWidget->show();

}
