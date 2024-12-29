/**
 * @file   FestoRobotSensorInterface.h
 * @Author Beran Cagli
 * @date   December, 2024
 * @brief  Header file for the FestoRobotSensorInterface class.
 * 
 * This file declares the FestoRobotSensorInterface class, which serves as an interface
 * for sensor interaction on the Festo robot platform.
 */

#ifndef FESTO_ROBOT_SENSOR_INTERFACE_H
#define FESTO_ROBOT_SENSOR_INTERFACE_H

#include "SensorInterface.h"
#include "FestoRobotAPI.h"

//! A class to interface with Festo robot sensors.
/*!
 * The FestoRobotSensorInterface class inherits from SensorInterface and provides
 * functionality to interact with the Festo robot's sensors.
 */
class FestoRobotSensorInterface : public SensorInterface {
protected:
    //! A pointer to the FestoRobotAPI instance.
    /*!
     * This member provides access to the robot's API for sensor-related operations.
     */
    FestoRobotAPI* robotAPI;

public:
    /**
     * @brief Constructor for the FestoRobotSensorInterface class.
     * 
     * Initializes the sensor interface for a specific sensor type on the Festo robot.
     * 
     * @param _robotAPI A pointer to the FestoRobotAPI instance used for robot interaction.
     * @param _sensorType A string indicating the type of the sensor (e.g., "IR", "Lidar").
     */
    FestoRobotSensorInterface(FestoRobotAPI* _robotAPI, std::string _sensorType);

    /**
     * @brief Virtual destructor.
     * 
     * Ensures proper cleanup of resources in derived classes.
     */
    virtual ~FestoRobotSensorInterface() = default;
};

#endif // FESTO_ROBOT_SENSOR_INTERFACE_H
