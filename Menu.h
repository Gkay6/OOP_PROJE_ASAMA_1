#ifndef MENU_H
#define MENU_H

#include "Encryption.h"
#include "LidarSensor.h"
#include "IRSensor.h"
#include "RobotController.h"
#include "SafeNavigation.h"
#include <string>
#include <iostream>

class Menu
{
private:
	FestoRobotAPI* robotAPI;
	LidarSensor lidar_sensor;
	IRSensor ir_sensor;
	RobotController robot_controller;
	SafeNavigation safe_navigation;
public:
	Menu(FestoRobotAPI* robotAPI);
	void Main_Menu();
	void Connection_Menu();
	void Motion_Menu();
	void Sensor_Menu();
	void Quit();
};
#endif // MENU_H