#include <Arduino.h>
#include <Servo.h>

//*Servo pin definitions-------------------------------------------------------------------------
int headRotationPin = 2;
int headNodPin = 3;
int headTiltPin = 4;

//*Servo object definitions----------------------------------------------------------------------
Servo headRotationServo;
Servo headNodServo;
Servo headTiltServo;

//*Servo min and max definitions----------------------------------------------------------------
int headRotationMin = 544, headRotationMax = 2400;
int headNodMin = 544, headNodMax = 2400;
int headTiltMin = 544, headTiltMax = 2400;

void setup()
{
  // put your setup code here, to run once:

  // Attaching the servo objects to the pin numbers defined above
  // The min and max microseconds for the servos are also defined here
  headRotationServo.attach(headRotationPin, headRotationMin, headRotationMax);
  headNodServo.attach(headNodPin, headNodMin, headNodMax);
  headTiltServo.attach(headTiltPin, headTiltMin, headTiltMax);
}

void loop()
{
  // put your main code here, to run repeatedly:
}