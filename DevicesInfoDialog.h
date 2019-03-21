#ifndef DEVICESINFODIALOG_H
#define DEVICESINFODIALOG_H

#include <QDialog>
#include <QTableWidgetItem>


class PortAudioWrapper;
class QListWidgetItem;
#include "PortAudioWrapper.h"
namespace Ui {
class DevicesInfoDialog;
}

class DevicesInfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DevicesInfoDialog(QWidget *parent, const PortAudioWrapper &myPortAudioWrapper);
    ~DevicesInfoDialog();

private slots:
    void on_comboBox_activated(int index);
    void on_listWidget_itemClicked(QListWidgetItem *item);

private:
    Ui::DevicesInfoDialog *ui;
     const PortAudioWrapper myPortAudioWrapper;

     void initTableItems();

     void listAllDevices();
     void listInputDevices();
     void listOutputDevices();
     void listDefaultDevices();


};

#endif // DEVICESINFODIALOG_H
