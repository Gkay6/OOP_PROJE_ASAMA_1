/**
 * @file   Menu.h
 * @author Gokay Taspinar
 * @date   22.12.2024
 * @brief  Header file for the Menu class
 */

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


 /**
  * @class Menu
  * @brief Class to connect all classes related to the robot
  *
  * Provides methods that safely moves the robot, which stops the robot 0.50 m before there is an obstacle
  */
class Menu
{
private:
	FestoRobotAPI* robotAPI; //!< Robot API
	IRSensor* ir_sensor = nullptr; //!< IR Sensor
	RobotController* robot_controller = nullptr; //!< Robot Controller for robot movement
	LidarSensor* lidar_sensor = nullptr; //!< Lidar Sensor
	SafeNavigation* safe_navigation = nullptr; //!< Safe Navigation for safe robot movement
	Mapper* mapper = nullptr; //!< Mapper to map the robots surroundings
	bool is_robot_connected; //!< Variable used to control the access of the menus
	
	//! Method used to create all the objects after a succesful connection
	void create_objects();
public:

	//! Constructor
	Menu(FestoRobotAPI* robotAPI);

	//! Opens the main menu
	void Main_Menu();

	//! Opens the connection menu
	void Connection_Menu();

	//! Opens the motion menu
	void Motion_Menu();

	//! Opens the sensor menu
	void Sensor_Menu();

	//! Closes the menu
	void Quit();
};
#endif // MENU_H