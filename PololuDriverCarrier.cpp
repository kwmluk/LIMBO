#include "PololuDriverCarrier.h"
#include "Arduino.h"
#include "MotorDriver.h"
#include "PinConfig.h"

//MLUK

PololuDriverCarrier::PololuDriverCarrier()
{
    
}

void PololuDriverCarrier::initialize(int pinM1IN1, int pinM1IN2, int pinM2IN1, int pinM2IN2, int pinENA, int pinSF)
{
    _pinENA = pinENA;
    _pinSF = pinSF;
    
    MotorL.initialize( pinM1IN1, pinM1IN2 );
    MotorR.initialize( pinM2IN2, pinM2IN1 );
    
    pinMode( _pinENA, OUTPUT );
    pinMode( _pinSF, INPUT );
}

void PololuDriverCarrier::enableDriverCarrier()
{
    digitalWrite( _pinENA, HIGH );
}

void PololuDriverCarrier::disableDriverCarrier()
{
    digitalWrite( _pinENA, LOW );
}

void PololuDriverCarrier::setSpeed(int spdPercent)
{
    MotorL.setSpeed(spdPercent);
    MotorR.setSpeed(spdPercent);
}

void PololuDriverCarrier::setSpeed(int spd_L, int spd_R)
{
    MotorL.setSpeed(spd_L);
    MotorR.setSpeed(spd_R);
}

void PololuDriverCarrier::setMotionForward()
{
    MotorL.setMotionForward();
    MotorR.setMotionForward();
}

void PololuDriverCarrier::setMotionReverse()
{
    MotorL.setMotionReverse();
    MotorR.setMotionReverse();
}

void PololuDriverCarrier::setMotionCW()
{
    MotorL.setMotionForward();
    MotorR.setMotionReverse();
}

void PololuDriverCarrier::setMotionCCW()
{
    MotorL.setMotionReverse();
    MotorR.setMotionForward();
}

bool PololuDriverCarrier::checkStatusFlag()
{
    return digitalRead( _pinSF );
}

void PololuDriverCarrier::move()
{
    MotorL.move();
    MotorR.move();
}