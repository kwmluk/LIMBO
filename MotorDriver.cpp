#include "Arduino.h"
#include "MotorDriver.h"

MotorDriver::MotorDriver()
{
    
}

void MotorDriver::initialize(int pinIN1, int pinIN2)
{
    _pinIN1 = pinIN1;
    _pinIN2 = pinIN2;
    
    pinMode(_pinIN1, OUTPUT);
    pinMode(_pinIN2, OUTPUT);
    
    baseInput = _pinIN1;
    pwmInput = _pinIN2;
}

void MotorDriver::setSpeed(int spdPercent)
{
    speed = spdPercent * 2.55;
}

void MotorDriver::setMotionForward()
{
    baseInput = _pinIN1;
    pwmInput = _pinIN2;
}

void MotorDriver::setMotionReverse()
{
    baseInput = _pinIN2;
    pwmInput = _pinIN1;
}

void MotorDriver::move()
{
    digitalWrite( baseInput, LOW );
    analogWrite(pwmInput, speed);
}
