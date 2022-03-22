#ifndef BODY_H
#define BODY_H

#include <Arduino.h>

class Body
{
private:
public:
    Body(void);
    void bodySetup();
    void setNeckAngles(int rotation, int tilt);
    void setHeadAngles(int rotation, int tilt, int nod);
    void setLateralWeightAngle(int angle);
    void balanceAtLateralAngle(int angle);
};

#endif