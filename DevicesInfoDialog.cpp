#include "DevicesInfoDialog.h"
#include "ui_DevicesInfoDialog.h"

DevicesInfoDialog::DevicesInfoDialog(QWidget *parent, const PortAudioWrapper &myPortAudioWrapper) :
    QDialog(parent),
    ui(new Ui::DevicesInfoDialog),
    myPortAudioWrapper(myPortAudioWrapper)
{
    ui->setupUi(this);

}

DevicesInfoDialog::~DevicesInfoDialog()
{
    delete ui;
}
