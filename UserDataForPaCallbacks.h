#ifndef USERDATAFORPACALLBACKS_H
#define USERDATAFORPACALLBACKS_H

typedef struct
{
    int          frameIndex;  /* Index into sample array. */
    int          maxFrameIndex;
    int          numSamples;
    float      *recordedSamples;
}
paTestData;


#endif // USERDATAFORPACALLBACKS_H
