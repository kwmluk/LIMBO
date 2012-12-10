//To be used with Pololu motors

#include "Arduino.h"

#ifndef LIMBO_EncoderDriver_h
#define LIMBO_EncoderDriver_h

class EncoderDriver
{
public:
    EncoderDriver();
    void initialize();
    
    void updateCount();
    int getCount();
private:
    int _pinOUTA;
    int _pinOUTB;
    int _intNumA;
    int count;
};

#endif
