#ifndef MENU_H
#define MENU_H

#include "Encryption.h"
#include "LidarSensor.h"
#include "IRSensor.h"
#include "Mapper.h"
#include "RobotController.h"
#include "SafeNavigation.h"
#include <string>
#include <iostream>

class Menu
{
private:
	FestoRobotAPI* robotAPI;
	IRSensor* ir_sensor = nullptr;
	RobotController* robot_controller = nullptr;
	LidarSensor* lidar_sensor = nullptr;
	SafeNavigation* safe_navigation = nullptr;
	Mapper* mapper = nullptr;
	bool is_robot_connected;
	void create_objects();
public:
	Menu(FestoRobotAPI* robotAPI);
	void Main_Menu();
	void Connection_Menu();
	void Motion_Menu();
	void Sensor_Menu();
	void Quit();
};
#endif // MENU_H