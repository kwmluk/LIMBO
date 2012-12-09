#include "PinConfig.h"
#include "PololuDriverCarrier.h"

PololuDriverCarrier driverCarrier;
void setup()
{
    Serial.begin(9600);
    driverCarrier.initialize(_M1IN1,_M1IN2,_M2IN1,_M2IN2,_M_ENA,_M_SF);
    driverCarrier.setSpeed(40);
    driverCarrier.setMotionForward();
    driverCarrier.enableDriverCarrier();
}

void loop()
{
    Serial.println(driverCarrier.checkStatusFlag());
    driverCarrier.enableDriverCarrier();
    driverCarrier.setSpeed(40);
    driverCarrier.setMotionReverse();
    driverCarrier.move();
    delay(2000);
    Serial.println(driverCarrier.checkStatusFlag());
    driverCarrier.setSpeed(85);
    driverCarrier.setMotionCCW();
    driverCarrier.move();
    delay(2000);
    Serial.println(driverCarrier.checkStatusFlag());
    driverCarrier.disableDriverCarrier();
    delay(2000);
}
