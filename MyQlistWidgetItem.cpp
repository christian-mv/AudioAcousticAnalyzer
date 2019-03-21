#include "MyQlistWidgetItem.h"
#include "PortAudioWrapper.h"

MyQlistWidgetItem::MyQlistWidgetItem(const AudioDevice *portAudioDevice)
    : QListWidgetItem () , audioDevice(portAudioDevice)
{
    setText(QString::fromStdString( audioDevice->toString() ));

    if(audioDevice->maxInputChannels()>0){
        setIcon(QIcon(":/media/microphone.png"));
    }
    else{
        setIcon(QIcon(":/media/speaker.png"));
    }
}

const AudioDevice *MyQlistWidgetItem::getAudioDevice() const
{
    return audioDevice;
}
