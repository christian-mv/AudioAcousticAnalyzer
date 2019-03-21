#ifndef MYQLISTWIDGETITEM_H
#define MYQLISTWIDGETITEM_H
#include <QListWidgetItem>


class AudioDevice;

class MyQlistWidgetItem : public QListWidgetItem
{
public:
    MyQlistWidgetItem(const AudioDevice * portAudioDevice);
    const AudioDevice* getAudioDevice() const;

private:
    const AudioDevice *audioDevice;
};


#endif // MYQLISTWIDGETITEM_H
