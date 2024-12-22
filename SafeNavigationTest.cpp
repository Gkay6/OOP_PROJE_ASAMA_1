#include <iostream>
#include "IRSensor.h"
#include "SafeNavigation.h"
#include "FestoRobotAPI.h"

FestoRobotAPI* robot;
int main() {

	robot = new FestoRobotAPI();
	robot->connect();

	RobotController rc(robot);
	IRSensor irs(robot);
	rc.connectRobot();
	SafeNavigation sn(&rc, &irs);

	Sleep(500);
	std::cout << "Safe move forward\n";
	sn.moveForwardSafe();
	Sleep(100);
	std::cout << "Safe move backward\n";
	sn.moveBackwardSafe();
	Sleep(100);
	std::cout << "Test ended\n";


	return 0;
}