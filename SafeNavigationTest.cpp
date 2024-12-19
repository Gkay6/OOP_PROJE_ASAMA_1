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
	//sn.moveBackwardSafe();
	sn.moveForwardSafe();

	Sleep(10000);




	//Sleep(1000000);


}