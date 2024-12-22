#include <iostream>
#include "IRSensor.h"
#include "FestoRobotAPI.h"


FestoRobotAPI* robot;
int main() {

	robot = new FestoRobotAPI();
	robot->connect();

	IRSensor irs(robot);
	Sleep(250);

	irs.update();
	std::cout << "\n\nSensor values using getRange():\n";
	for (int i = 0; i < 9; i++) {
		std::cout << irs.getRange(i) << "\n";
	}

	robot->move(FORWARD);
	Sleep(500);

	irs.update();
	std::cout << "\n\nSensor values using [] operator:\n";
	for (int i = 0; i < 9; i++) {
		std::cout << irs[i] << "\n";
	}

	std::cout << "Test ended\n";


}