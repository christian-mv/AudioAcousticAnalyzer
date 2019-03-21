#include "MainWindow.h"
#include <QApplication>
#include "PortAudioWrapper.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PortAudioWrapper portAudioObject;
    MainWindow w;

    w.show();


    return a.exec();
}
