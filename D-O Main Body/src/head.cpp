#include <head.h>
#include <Arduino.h>
#include <Servo.h>

/*
The head's movements are defined as follows:
Also to note: up, down, left, and right are relative to the robot

Neck Rotation: This is the larger rod that rotates the neck and head assembly around the wheel
Neck Tilt: This is the smaller rod that changes the angle of the neck and head assembly

Head Rotation: This is the rotation of the cone head in the z-axis. Positive is right, negative is left
Head Nod: This is the angle of the head up-to-down. Positive is looking up, negative is looking down
Head Tilt: This is the angle of the head side-to-side. Positive is right, negative is left
*/

//*variables for the different rotations of the head and neck assembly----------------------------
float neckRotationAngle;
float neckTiltAngle;
float headRotationAngle;
float headNodAngle;
float headTiltAngle;

//*Servo pin definitions-------------------------------------------------------------------------
int neckRotationPin = 9;
int neckTiltPin = 10;

//*Servo object definitions----------------------------------------------------------------------
Servo neckRotationServo;
Servo neckTiltServo;

//*Servo min and max definitions----------------------------------------------------------------

//*Communication class for communicating with the head Arduino
Communication comm;

Head::Head(void) {}

void Head::headSetup()
{
  neckRotationServo.attach(neckRotationPin);
  neckTiltServo.attach(neckTiltPin);
}

/** setNeckRotation(float angle)
 * This sets the neck rotation angle in degrees.
 * This is the rotation of the entire head and neck assembly relative to the main body
 * 0 degrees is straight up, positive is forward and negative is backward
 * Max angle is +/- 25 degrees
 * The angle is stored in the class variable so it can be retrieved later
 */
void Head::setNeckRotation(int angle)
{
  neckRotationAngle = angle;
  neckRotationServo.write(angle);
}

/** setNeckTilt(float angle)
 * This sets the neck tilt angle in degrees.
 * This is the tilt of the entire head and neck assembly relative to the rotation bar
 * 0 degrees is perpendicular to the rotation bar, positive is tilting the head down and negative is tilting the head up
 * Max angle is +/- 25 degrees
 * The angle is stored in the class variable so it can be retrieved later
 */
void Head::setNeckTilt(int angle)
{
  neckTiltAngle = angle;
  neckTiltServo.write(angle); // Set the servo to the angle with the microseconds value
}

// HEAD COMMUNICATION---------------------------

/** setHeadRotation(float angle)
 * This sets the head rotation angle in degrees.
 * This is the rotation of the entire head
 * 0 degrees is forward, positive is right and negative is left
 * Max angle is +/- 90 degrees
 * The angle is stored in the class variable so it can be retrieved later
 */
void Head::setHeadRotation(int angle)
{
  headRotationAngle = angle;
  comm.sendHeadRotation(angle);
}

/** setHeadNod(float angle)
 * This sets the head nod angle in degrees.
 * This is the "nodding" motion of the entire head
 * 0 degrees is level (relative to the neck base), positive is up and negative is down
 * Max angle is +/- 30 degrees
 * The angle is stored in the class variable so it can be retrieved later
 * TODO: Make the angle verification for max/min angles
 */
void Head::setHeadNod(int angle)
{
  headNodAngle = angle;
  comm.sendHeadNod(angle);
}

/** setHeadTilt(float angle)
 * This sets the head tilt angle in degrees.
 * This is the side-to-side leaning motion of the entire head
 * 0 degrees is level (relative to the neck base), positive is leaning to the right and negative is leaning to the left
 * Max angle is +/- 30 degrees
 * The angle is stored in the class variable so it can be retrieved later
 * TODO: Make the angle verification for max/min angles
 */
void Head::setHeadTilt(int angle)
{
  headTiltAngle = angle;
  comm.sendHeadTilt(angle);
}