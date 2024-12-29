/**
 * @file   SensorInterface.cpp
 * @Author Beran Cagli
 * @date   December, 2024
 * @brief  Implementation of the SensorInterface class.
 *
 * This file contains the implementation of the SensorInterface class,
 * which defines the base functionality for all sensor types.
 */

#include "SensorInterface.h"

/**
 * @brief Constructor for the SensorInterface class.
 * 
 * Initializes the SensorInterface with a specific sensor type.
 * 
 * @param _sensorType A string representing the type of the sensor (e.g., "IR", "Lidar").
 */
SensorInterface::SensorInterface(std::string _sensorType)
    :sensorType(_sensorType)
{
}

/**
 * @brief Gets the type of the sensor.
 * 
 * @return A string representing the sensor type.
 */
std::string SensorInterface::getSensorType() const
{
    return this->sensorType;
}
