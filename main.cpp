#include "FestoRobotAPI.h"
#include "Menu.h"
#include <iostream>

FestoRobotAPI* robot;

// main function
int main() {
	//Create a robot object
	robot = new FestoRobotAPI();

	Menu robot_control_menu(robot);


	return 0;
}
