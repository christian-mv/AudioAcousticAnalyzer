#include "DevicesInfoDialog.h"
#include "ui_DevicesInfoDialog.h"
#include "MyQlistWidgetItem.h"
#include <QDebug>



DevicesInfoDialog::DevicesInfoDialog(QWidget *parent, const PortAudioWrapper &myPortAudioWrapper) :
    QDialog(parent),
    ui(new Ui::DevicesInfoDialog),
    myPortAudioWrapper(myPortAudioWrapper)
{    
    ui->setupUi(this);

    listAllDevices();

    // this gurantees that the information of the first item is shown in the first load
    if(ui->listWidget->count()>0){
        // this executes on_listWidget_itemClicked()
        emit ui->listWidget->itemClicked(ui->listWidget->itemAt(0,0));
    }

}

DevicesInfoDialog::~DevicesInfoDialog()
{
    delete ui;
}

void DevicesInfoDialog::on_comboBox_activated(int index)
{
    ui->listWidget->clear();

    switch (index) {
    case 0:
        listAllDevices();
        break;
    case 1:
        listInputDevices();
        break;
    case 2:
        listOutputDevices();
        break;
    case 3:
        listDefaultDevices();
        break;
    default:
        break;
        }

    if(ui->listWidget->count()>0){
        ui->listWidget->setCurrentRow(0);
    }
}

void DevicesInfoDialog::listAllDevices()
{

    for(auto device: myPortAudioWrapper.getDevicesList()){

        ui->listWidget->addItem( new MyQlistWidgetItem(device) );
    }
}

void DevicesInfoDialog::listInputDevices()
{

    for(auto device: myPortAudioWrapper.getDevicesList()){
        if(device->maxInputChannels()>0){
            ui->listWidget->addItem( new MyQlistWidgetItem(device) );
        }
    }
}

void DevicesInfoDialog::listOutputDevices()
{

    for(auto device: myPortAudioWrapper.getDevicesList()){
        if(device->maxOutputChannels()>0){
            ui->listWidget->addItem( new MyQlistWidgetItem(device) );
        }
    }
}

void DevicesInfoDialog::listDefaultDevices()
{

    for(auto device: myPortAudioWrapper.getDevicesList()){
        if(device->indexDevice() == myPortAudioWrapper.getDefaultInputDeviceIndex()
                || device->indexDevice() == myPortAudioWrapper.getDefaultOutputDeviceIndex()){
            ui->listWidget->addItem( new MyQlistWidgetItem(device) );
        }
    }
}


void DevicesInfoDialog::on_listWidget_itemClicked(QListWidgetItem *item)
{
    auto listWidgetItem = static_cast<MyQlistWidgetItem*>( item );

    auto device = listWidgetItem->getAudioDevice();
    QString str;
    str+="<br><br><b>Device Index:</b> "+ QString::number( device->indexDevice() );
    str+="<br><br><b>Name:</b> "+ QString::fromStdString( device->name() );
    str+="<br><br><b>Host API:</b> "+ QString::fromStdString( device->hostApi() );
    str+="<br><br><b>Max Inputs:</b> "+ QString::number( device->maxInputChannels() ) + " channels";
    str+="<br><br><b>Max Outputs:</b> "+ QString::number( device->maxOutputChannels() ) + " channels";
    str+="<br><br><b>Default Low Input Latency:</b> "+ QString::number( device->defaultLowInputLatency() ) + " seconds";
    str+="<br><br><b>Default Low Output Latency:</b> "+ QString::number( device->defaultLowOutputLatency() ) + " seconds";
    str+="<br><br><b>Default High Input Latency:</b> "+ QString::number( device->defaultHighInputLatency() ) + " seconds";
    str+="<br><br><b>Default High Output Latency:</b> "+ QString::number( device->defaultHighOutputLatency() ) + " seconds";
    str+="<br><br><b>Default Sample Rate:</b> "+ QString::number( device->defaultSampleRate() ) + " samples per second";


    ui->textEdit->setText(str);
//    QString str;
//    str = "\r\n"+"Device Index"+"\r\n"+"Name"+"\r\n"+"Host API"
//          +"\r\n"+"Max Inputs"+"\r\n"+"Max Outputs"
//         +"\r\n"+"Default Low Input Latency"
//        +"\r\n"+"Default Low Output Latency"
//       +"\r\n"+"Default High Input Latency"
//      +"\r\n"+"Default High Output Latency"
//     +"\r\n"+"Default Sample Rate";

//    ui->tableWidget->itemAt(2,0)->setText( QString::number( device->indexDevice() ) );
//    ui->tableWidget->itemAt(2,0)->setText(  QString::fromStdString( device->name() ) );
//    ui->tableWidget->itemAt(2,0)->setText(  QString::fromStdString( device->hostApi() ) );
//    ui->tableWidget->itemAt(3,0)->setText( QString::number( device->maxInputChannels() ) );
//    ui->tableWidget->itemAt(4,0)->setText( QString::number( device->maxOutputChannels() ) );
//    ui->tableWidget->itemAt(5,0)->setText( QString::number( device->defaultLowInputLatency() ) );
//    ui->tableWidget->itemAt(6,0)->setText( QString::number( device->defaultLowOutputLatency() ) );
//    ui->tableWidget->itemAt(7,0)->setText( QString::number( device->defaultHighInputLatency() ) );
//    ui->tableWidget->itemAt(8,0)->setText( QString::number( device->defaultHighOutputLatency() ) );
//    ui->tableWidget->itemAt(9,0)->setText( QString::number( device->defaultSampleRate() ) );


}
