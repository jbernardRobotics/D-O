#include <Arduino.h>
#include <head.h>


Head head;


void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  head.headSetup();
}

void loop()
{
  // put your main code here, to run repeatedly:
  // head.setNeckRotation(0);
  // delay(1000);
  // head.setNeckRotation(20);
  // delay(1000);
}