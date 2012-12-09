#ifndef _PololuDriverCarrier_h
#define _PololuDriverCarrier_h

#include "Arduino.h"
#include "MotorDriver.h"
#include "PinConfig.h"

//Use with Dual MC33926 Motor Driver Carrier, controls 2 Motors
//MLUK

class PololuDriverCarrier
{
public:
    PololuDriverCarrier();
    
    void initialize(int pinM1IN1, int pinM1IN2, int pinM2IN1, int pinM2IN2, int pinENA, int pinSF);
    
    void enableDriverCarrier();
    void disableDriverCarrier();
    
    void setSpeed( int spdPercent );
    void setSpeed( int spd_L, int spd_R );
    
    void setMotionForward();
    void setMotionReverse();
    
    void setMotionCW();     //Clockwise
    void setMotionCCW();    //Counterclockwise
    
    bool checkStatusFlag();
    
    void move();
private:
    int _pinENA;
    int _pinSF;
    
    MotorDriver MotorL;
    MotorDriver MotorR;
};

#endif
