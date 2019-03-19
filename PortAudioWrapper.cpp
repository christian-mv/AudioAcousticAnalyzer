#include "PortAudioWrapper.h"
#include <iostream>

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

