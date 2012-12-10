#include "EncoderDriver.h"
#include "Arduino.h"

EncoderDriver::EncoderDriver()
{
    
}

void EncoderDriver::initialize()
{
    count = 0;
    
    _pinOUTA = 3;
    _pinOUTB = 2;
    
    pinMode( _pinOUTA, INPUT );
    pinMode( _pinOUTB, INPUT );
    
    digitalWrite( _pinOUTA, HIGH ); //turn on pull-up
    digitalWrite( _pinOUTB, HIGH );
    
    //1 == pin3 == pinOUTA (placed in Main)
    //attachInterrupt(1, updateCount, FALLING);
}

void EncoderDriver::updateCount()
{
    //same as if(digitalRead(2)==HIGH), pinOUTB
    if (PIND & 0b00000100)    count++;
    else                      count--;
}

int EncoderDriver::getCount()
{
    return count;
}