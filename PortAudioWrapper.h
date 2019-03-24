#ifndef PORTAUDIOWRAPPER_H
#define PORTAUDIOWRAPPER_H

#include "portaudio.h"
#include <string>
#include <list>



class AudioDevice; // declaration



// this class is intended to be a wrapper for portaudio.h
class PortAudioWrapper{
public:
    PortAudioWrapper();
    ~PortAudioWrapper();
    std::string errorToText() const {return  errorText;}
    const std::list<AudioDevice*> getDevicesList() const;
    static int getDefaultInputDeviceIndex() ;
    static int getDefaultOutputDeviceIndex() ;
    void record();
    void play();


private:
    std::string errorText;
    PaError err;
    PaDeviceIndex numDevices;
    std::list<AudioDevice*> devicesList;




};

class AudioDevice
{
public:
    AudioDevice(const PaDeviceInfo *deviceInfo, const PaDeviceIndex indexDevice);
    ~AudioDevice();

    std::string toString() const;

    // getters methods
    int indexDevice() const {return paIndexDevice;}
    std::string  name() const {return deviceInfo->name;}
    std::string hostApi() const {return Pa_GetHostApiInfo( deviceInfo->hostApi )->name;}
    int maxInputChannels() const {return deviceInfo->maxInputChannels;}
    int maxOutputChannels() const {return deviceInfo->maxOutputChannels;}
    double defaultSampleRate() const {return deviceInfo->defaultSampleRate;}
    double defaultLowInputLatency() const {return deviceInfo->defaultLowInputLatency;}
    double defaultLowOutputLatency() const {return deviceInfo->defaultLowOutputLatency;}
    double defaultHighInputLatency() const {return deviceInfo->defaultHighInputLatency;}
    double defaultHighOutputLatency() const {return deviceInfo->defaultHighInputLatency;}

private:
    const PaDeviceInfo *deviceInfo;
    const PaDeviceIndex paIndexDevice;

};

#endif // PORTAUDIOWRAPPER_H
