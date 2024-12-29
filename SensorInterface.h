/**
 * @file   SensorInterface.h
 * @Author Beran Cagli
 * @date   December, 2024
 * @brief  Header file for the SensorInterface class.
 *
 * This file declares the SensorInterface class, which serves as an abstract base class
 * for various sensor types.
 */

#ifndef SENSOR_INTERFACE_H
#define SENSOR_INTERFACE_H

#include <string>

//! Abstract base class for sensors.
/*!
 * The SensorInterface class provides a common interface for all types of sensors.
 * It includes methods for updating sensor data and retrieving sensor values.
 */
class SensorInterface {
private:
    //! The type of the sensor.
    /*!
     * This member stores the type of the sensor as a string (e.g., "IR", "Lidar").
     */
    std::string sensorType;

public:
    /**
     * @brief Constructor for the SensorInterface class.
     * 
     * Initializes the SensorInterface with a specific sensor type.
     * 
     * @param _sensorType A string representing the type of the sensor.
     */
    SensorInterface(std::string _sensorType);

    /**
     * @brief Virtual destructor.
     * 
     * Ensures proper cleanup of resources in derived classes.
     */
    virtual ~SensorInterface() = default;

    /**
     * @brief Updates the sensor data.
     * 
     * This is a pure virtual function that must be implemented by derived classes.
     * 
     * @param index An optional parameter to specify the index of the data to update. Default is -1.
     */
    virtual void update(int index = -1) = 0;

    /**
     * @brief Gets the type of the sensor.
     * 
     * @return A string representing the sensor type.
     */
    std::string getSensorType() const;

    /**
     * @brief Retrieves the value of the sensor data.
     * 
     * This is a pure virtual function that must be implemented by derived classes.
     * 
     * @param index The index of the sensor data to retrieve.
     * @return A double representing the sensor data value.
     */
    virtual double getSensorValue(int index) const = 0;
};

#endif // SENSOR_INTERFACE_H
