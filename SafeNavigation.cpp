#include "SafeNavigation.h"

SafeNavigation::SafeNavigation(RobotController* _controller, IRSensor* _ir_sensor) {
	ir_sensor = _ir_sensor;
	controller = _controller;
	state = STOP;
}

void SafeNavigation::moveForwardSafe() {

	ir_sensor->update();
	state = MOVING;
	controller->moveForward();

	while (state == MOVING) {

		// Updating 3 front sensors
		ir_sensor->update(8);
		ir_sensor->update(0);
		ir_sensor->update(1);


		if (ir_sensor->getRange(0) < 0.50 + 0.16) {
			state = STOP;
		}else if (ir_sensor->getRange(8) < 0.22) {
			state = STOP;
		}
		else if (ir_sensor->getRange(1) < 0.22) {
			state = STOP;
		}
	}
	
	controller->stop();
}

void SafeNavigation::moveBackwardSafe() {

	ir_sensor->update();
	state = MOVING;
	controller->moveBackward();

	while (state == MOVING) {

		// Updating 2 back sensors
		ir_sensor->update(4);
		ir_sensor->update(5);


		if (ir_sensor->getRange(4) < 0.50 + 0.16) {
			state = STOP;
		}
		else if (ir_sensor->getRange(5) < 0.50 + 0.16) {
			state = STOP;
		}
	}

	controller->stop();
}