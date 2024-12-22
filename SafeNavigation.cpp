/**
 * @file   SafeNavigation.cpp
 * @author Gokay Taspinar
 * @date   22.12.2024
 * @brief  Implementation of the SafeNavigation class methods
 */

#include "SafeNavigation.h"

// Constructor
SafeNavigation::SafeNavigation(RobotController* _controller, IRSensor* _ir_sensor) {
	ir_sensor = _ir_sensor;
	controller = _controller;
	state = STOP;
}


// Moves the robot forward until there is an obstacle in 0.50 m
void SafeNavigation::moveForwardSafe() {

	// Updating the sensors and stopping the robot takes time
	// In order to stop at desired distance
	// Loop must end before the sensors showing 0.50 m
	const double FORWARD_EARLY_STOP_DISTANCE = 0.16;

	ir_sensor->update();

	// Starts moving the robot
	state = MOVING;
	controller->moveForward();

	while (state == MOVING) {

		// Only updates 3 front sensors
		// To have a faster reaction time
		ir_sensor->update(8);
		ir_sensor->update(0);
		ir_sensor->update(1);

		// 45 degree sensors are used to prevent crashes at last moment
		if (ir_sensor->getRange(0) < 0.50 + FORWARD_EARLY_STOP_DISTANCE) {
			state = STOP;
		}else if (ir_sensor->getRange(8) < 0.25) {
			state = STOP;
		}
		else if (ir_sensor->getRange(1) < 0.25) {
			state = STOP;
		}
	}
	
	// Stops the robot
	controller->stop();
}


// Moves the robot backward until there is an obstacle in 0.50 m
void SafeNavigation::moveBackwardSafe() {

	// Updating the sensors and stopping the robot takes time
	// In order to stop at desired distance
	// Loop must end before the sensors showing 0.50 m
	const double BACKWARD_EARLY_STOP_DISTANCE = 0.16;
	ir_sensor->update();

	state = MOVING;
	controller->moveBackward();

	while (state == MOVING) {

		// Only updates 2 bask sensors
		// To have a faster reaction time
		ir_sensor->update(4);
		ir_sensor->update(5);

		if (ir_sensor->getRange(4) < 0.50 + BACKWARD_EARLY_STOP_DISTANCE) {
			state = STOP;
		}
		else if (ir_sensor->getRange(5) < 0.50 + BACKWARD_EARLY_STOP_DISTANCE) {
			state = STOP;
		}
	}

	// Stops the robot
	controller->stop();
}