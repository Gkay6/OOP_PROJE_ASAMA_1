#include <iostream>
#include "IRSensor.h"
#include "SafeNavigation.h"
#include "FestoRobotAPI.h"
#include "FestoRobotInterface.h"
#include "vector"

FestoRobotAPI* robot;
int main() {

	robot = new FestoRobotAPI();
	robot->connect();

	FestoRobotInterface* robot_interface = new FestoRobotInterface(robot);
	std::list<SensorInterface*> sensorList;
	RobotController rc(sensorList, robot_interface, "Name", 1234);
	rc.openAccess(1234);

	IRSensor irs(robot);
	rc.connectRobot();
	SafeNavigation sn(&rc, &irs);


	// Tests
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