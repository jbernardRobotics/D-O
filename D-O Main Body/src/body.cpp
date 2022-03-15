#include <Arduino.h>
#include <Servo.h>
#include <head.h>
#include <body.h>

//*Servo pin definitions-------------------------------------------------------------------------
int lateralWeightPin = 11; // TODO: pick real pins
int driveMotorPin = 12;

//*Servo object definitions----------------------------------------------------------------------
Servo lateralWeightServo;

//*Head object definition----------------------------------------------------------------------
Head head;

Body::Body(void) {}

void Body::bodySetup()
{
    lateralWeightServo.attach(lateralWeightPin);
    head.headSetup();
}

/** setNeckAngles(int rotation, int tilt)
 * @param rotation: 0 degrees is straight up, positive is forward and negative is backward. Max angle is +/- 25 degrees
 * @param tilt: 0 degrees is perpendicular to the rotation bar, positive is tilting the head down and negative is tilting the head up. Max angle is +/- 25 degrees
 * This sets the neck rotation and tilt angle in degrees.
 * This is the rotation of the entire head and neck assembly relative to the main body and the tilt relative to the rotation bar
 */
void setNeckAngles(int rotation, int tilt)
{
    head.setNeckRotation(rotation);
    head.setNeckTilt(tilt);
}

/** setNeckAngles(int rotation, int tilt)
 * @param rotation: 0 degrees is straight up, positive is forward and negative is backward. Max angle is +/- 25 degrees
 * @param tilt: 0 degrees is perpendicular to the rotation bar, positive is tilting the head down and negative is tilting the head up. Max angle is +/- 25 degrees
 * @param nod: 0 degrees is perpendicular to the rotation bar, positive is tilting the head down and negative is tilting the head up. Max angle is +/- 25 degrees
 * This sets the neck rotation and tilt angle in degrees.
 * This is the rotation of the entire head and neck assembly relative to the main body and the tilt relative to the rotation bar
 */
void setHeadAngles(int rotation, int tilt, int nod)
{
    head.setHeadRotation(rotation);
    head.setHeadTilt(tilt);
    head.setHeadNod(tilt);
}
