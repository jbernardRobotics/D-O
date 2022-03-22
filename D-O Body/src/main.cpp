#include <Arduino.h>
#include <body.h>

Body body;

int lateralWeightTest[8] = {0, 15, 25, 15, 0, -15, -25, -15};
int neckRotationTest[8] = {0, 15, 25, 15, 0, -15, -25, -15};
int neckTiltTest[8] = {0, 15, 25, 15, 0, -15, -25, -15};

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  body.bodySetup();
}

void loop()
{
  //*Testing the lateral weight servo--------
  for (int i = 0; i < 8; i++)
  {
    body.setLateralWeightAngle(lateralWeightTest[i]);
    delay(1000);
  }
  // TODO: Check the min anx max values. Going to have to change them from 0 and 180 to something smaller

  /* //TODO: Next Tests--------------------------------------------------------------
    //*Testing the Neck Rotation servo--------
    for(int i = 0; i < 8; i++){
      body.head.setHeadRotation(neckRotationTest[i]);
      delay(1000);
    }
    //TODO: Check the min anx max values. Going to have to change them from 0 and 180 to something smaller

    //*Testing the Neck Tilt servo--------
    for(int i = 0; i < 8; i++){
      body.head.setHeadTilt(neckTiltTest[i]);
      delay(1000);
    }
    //TODO: Check the min anx max values. Going to have to change them from 0 and 180 to something smaller

  */
}