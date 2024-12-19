#ifndef SAFENAVIGATION_H
#define SAFENAVIGATION_H
#include "IRSensor.h"
#include "RobotController.h"

enum MOVESTATE {
	MOVING,
	STOP
};

class SafeNavigation
{
private:
	IRSensor* ir_sensor;
	RobotController* controller;
	MOVESTATE state;
public:
	SafeNavigation(RobotController* _controller, IRSensor* _ir_sensor);
	void moveForwardSafe();
	void moveBackwardSafe();
};

#endif // SAFENAVIGATION_H
