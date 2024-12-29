/**
 * @file   SafeNavigation.h
 * @author Gokay Taspinar
 * @date   22.12.2024
 * @brief  Header file for the SafeNavigation class
 */


#ifndef SAFENAVIGATION_H
#define SAFENAVIGATION_H
#include "IRSensor.h"
#include "RobotController.h"
#include "FestoRobotSensorInterface.h"

 //! Robot move state 
enum MOVESTATE {
	MOVING, /*!< Robot is moving */
	STOP /*!< Robot stopped */
};

/**
 * @class SafeNavigation
 * @brief Class to safely move the robot
 * 
 * Provides methods that safely moves the robot, which stops the robot 0.50 m before there is an obstacle
 */
class SafeNavigation
{
private:
	SensorInterface* ir_sensor; //!< IR Sensor is used to detect obstacles
	RobotController* controller; //!< Controller is used to move and stop the robot
	MOVESTATE state; //!< Robots move state
public:
	
	//! Constructor
	SafeNavigation(RobotController* _controller, SensorInterface* _ir_sensor);
	
	//! Moves the robot forward until there is an obstacle in 0.50 m
	void moveForwardSafe();

	//! Moves the robot backward until there is an obstacle in 0.50 m
	void moveBackwardSafe();
};

#endif // SAFENAVIGATION_H
