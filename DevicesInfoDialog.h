#ifndef DEVICESINFODIALOG_H
#define DEVICESINFODIALOG_H

#include <QDialog>


class PortAudioWrapper;
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

private:
    Ui::DevicesInfoDialog *ui;
     const PortAudioWrapper myPortAudioWrapper;
};

#endif // DEVICESINFODIALOG_H
