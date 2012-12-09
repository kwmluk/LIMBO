#ifndef MotorDriver_h
#define MotorDriver_h

#include "Arduino.h"

//Class for driving a single motor
//MLUK

class MotorDriver
{
public:
    MotorDriver();
    void initialize(int pinIN1, int pinIN2);
    void setSpeed( int spdPercent );
    void setMotionForward();
    void setMotionReverse();
    
    //Each call of move updates both direction and speed
    void move();
private: 
    int _pinIN1;    //Input 1
    int _pinIN2;    //Input 2
    
    //For direction control
    int baseInput;  //Default IN1
    int pwmInput;   //Default IN2
    
    //For speed control
    int speed;
};

#endif
