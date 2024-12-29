/**
 * @file   FestoRobotSensorInterface.cpp
 * @Author Beran Cagli
 * @date   December, 2024
 * @brief  Implementation of the FestoRobotSensorInterface class.
 *
 * This file contains the implementation of the FestoRobotSensorInterface class,
 * which is used to interact with sensors on the Festo robot platform.
 */

#include "FestoRobotSensorInterface.h"

/**
 * @brief Constructor for the FestoRobotSensorInterface class.
 * 
 * Initializes a sensor interface for the Festo robot.
 * 
 * @param _robotAPI A pointer to the FestoRobotAPI object used to interact with the robot.
 * @param _sensorType A string representing the type of the sensor (e.g., "IR", "Lidar").
 */
FestoRobotSensorInterface::FestoRobotSensorInterface(FestoRobotAPI* _robotAPI, std::string _sensorType)
	:robotAPI(_robotAPI), SensorInterface(_sensorType)
{
}
