#include "PortAudioWrapper.h"
#include <iostream>
#include <QDebug>
#include "RecordAndPlay.h"

PortAudioWrapper::PortAudioWrapper()
    : errorText("")
{
    // init PortAudio
    err = Pa_Initialize();
    if( err != paNoError ){
        errorText = errorText + "\r\n" + Pa_GetErrorText( err );
        std::cerr<<"\r\nPortAudio Error code "<<err<<": "<<errorText<<std::endl;
        return;
    }
    std::cout<<"\r\nPortAudio has succesfully initialized"<<std::endl;

    // count and load devices
    numDevices = Pa_GetDeviceCount();
    std::cout<<"\r\n"<<numDevices<<" Devices Udentified"<<std::endl;
    if( numDevices < 0 )
    {
        err = numDevices;
        errorText = errorText + "\r\n" + Pa_GetErrorText( err );
        std::cerr<<"\r\nPortAudio Error code "<<err<<": "<<errorText<<std::endl;
        return;
    }
    else {
        for(int i=0; i<numDevices; i++)
        {
           devicesList.push_back(new AudioDevice(Pa_GetDeviceInfo( i ), i));

        }
    }

}

PortAudioWrapper::~PortAudioWrapper()
{

    err = Pa_Terminate();
    if( err != paNoError ){
        errorText = Pa_GetErrorText( err );
        std::cerr<<"\r\nPortAudio Error code "<<err<<": "<<errorText<<std::endl;
    }

    // free memory used by AudioDevice objects
    for(auto x: devicesList){ delete x; }

    std::cout<<"\r\nPortAudio has succesfully terminated"<<std::endl;
}

const std::list<AudioDevice *> PortAudioWrapper::getDevicesList() const
{
    return devicesList;
}

int PortAudioWrapper::getDefaultInputDeviceIndex()
{
    return Pa_GetDefaultInputDevice();
}

int PortAudioWrapper::getDefaultOutputDeviceIndex()
{
    return Pa_GetDefaultOutputDevice();
}

void PortAudioWrapper::record()
{

    data = new paTestData();

    RecordAndPlay::record(data);


//    for(auto i = 0; i<data.numSamples; i++){
//        qDebug()<<"i["<<i<<"]: "<<data.recordedSamples[i];
//    }
}

void PortAudioWrapper::play()
{
    RecordAndPlay::play(data);
}



AudioDevice::AudioDevice(const PaDeviceInfo *deviceInfo, const PaDeviceIndex paIndexDevice)
    : deviceInfo(deviceInfo),
      paIndexDevice(paIndexDevice)
{
    std::cout<<"\r\nCreating AudioDevice object["<<indexDevice()<<"]"<<std::endl;

}

AudioDevice::~AudioDevice()
{
    std::cout<<"\r\nDeleting AudioDevice object["<<indexDevice()<<"]"<<std::endl;
}

std::string AudioDevice::toString() const
{
    std::string str;


    str += std::to_string(indexDevice()) + ") ";

    if(maxInputChannels()>0 &&
            indexDevice()==PortAudioWrapper::getDefaultInputDeviceIndex()){
        str += " [DEFAULT INPUT DEVICE]\r\n";
    }

    if(maxOutputChannels()>0 &&
            indexDevice()==PortAudioWrapper::getDefaultOutputDeviceIndex()){
        str += " [DEFAULT OUTPUT DEVICE]\r\n";
    }


    str +=  name() + "\r\n";

    return str;
}


