#-------------------------------------------------
#
# Project created by QtCreator 2019-03-19T15:17:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AudioAcousticAnalyzer
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        MainWindow.cpp \
    DevicesInfoDialog.cpp \
    PortAudioWrapper.cpp \
    MyQlistWidgetItem.cpp

HEADERS += \
        MainWindow.h \
    DevicesInfoDialog.h \
    PortAudioWrapper.h \
    MyQlistWidgetItem.h

FORMS += \
        MainWindow.ui \
    DevicesInfoDialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



# adding PortAudio library
INCLUDEPATH += "../3rdparty_libraries/portaudio/headers"

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../3rdparty_libraries/portaudio/bin/windows/portaudio_64bits/ -lportaudio_x64
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../3rdparty_libraries/portaudio/bin/windows/portaudio_64bits/ -lportaudio_x64d
else:unix: LIBS += -L$$PWD/../3rdparty_libraries/portaudio/bin/windows/portaudio_64bits/ -lportaudio_x64

INCLUDEPATH += $$PWD/../3rdparty_libraries/portaudio/bin/windows/portaudio_64bits
DEPENDPATH += $$PWD/../3rdparty_libraries/portaudio/bin/windows/portaudio_64bits

RESOURCES += \
    resources.qrc



