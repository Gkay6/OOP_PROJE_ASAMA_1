#ifndef SAFENAVIGATION_H
#define SAFENAVIGATION_H
#include "IRSensor.h"
#include "RobotController.h"


enum MOVESTATE {
	MOVING, // Robot is moving
	STOP    // Robot stopped
};

class SafeNavigation
{
private:
	IRSensor* ir_sensor; // IR Sensor is used to detect obstacles
	RobotController* controller; // Controller is used to move and stop the robot
	MOVESTATE state; // Robots move state
public:
	
	// Constructor
	SafeNavigation(RobotController* _controller, IRSensor* _ir_sensor);
	
	// Moves the robot forward until there is an obstacle in 0.50 m
	void moveForwardSafe();

	// Moves the robot bakward until there is an obstacle in 0.50 m
	void moveBackwardSafe();
};

#endif // SAFENAVIGATION_H
