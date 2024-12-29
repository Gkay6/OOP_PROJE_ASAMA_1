/*!
 * \file LidarSensor.h
 * \author Utku Bugra Namkazan
 * \date 22.12.2024
 * \brief Header file for the LidarSensor class, which gets data from lidar sensors from the robot using the FestoRobotAPI.
 */
#ifndef LIDAR_SENSOR_H
#define LIDAR_SENSOR_H
#include "FestoRobotSensorInterface.h"

 /*! \class LidarSensor
  *  \brief A class to interact with and retrieve data from the lidar sensors on a robot.
  */
class LidarSensor : public FestoRobotSensorInterface
{
private:
    double* ranges; //!< Array storing the distance readings from the lidar sensors.
    int rangeNumber; //!< Number of lidar sensors available on the robot.

public:
    /*! \brief Constructor that initializes the LidarSensor with a given API object.
     *  \param _robotAPI Pointer to an instance of FestoRobotAPI.
     */
    LidarSensor(FestoRobotAPI* _robotAPI);

    /*! \brief Destructor to clean up allocated resources. */
    ~LidarSensor();

    /*! \brief Retrieves the number of lidar sensors on the robot.
    *  \return The count of lidar sensors.
    */
    int getRangeNumber() const;

    /*! \brief Retrieves the distance reading of a specific lidar sensor.
     *  \param index Index of the sensor.
     *  \return Distance reading from the specified lidar sensor.
     */
    double getRange(int index) const;

    /*! \brief Retrieves the maximum distance value and its index from the sensors.
     *  \param index Reference to store the index of the sensor with the maximum value.
     *  \return The maximum distance reading among all sensors.
     */
    double getMax(int& index) const;

    /*! \brief Retrieves the minimum distance value and its index from the sensors.
     *  \param index Reference to store the index of the sensor with the minimum value.
     *  \return The minimum distance reading among all sensors.
     */
    double getMin(int& index) const;

    /*! \brief Updates the lidar sensor readings. */
    void update(int index = -1) override;

    /*! \brief Access operator to retrieve or modify the distance reading of a specific sensor.
     *  \param index Index of the sensor.
     *  \return Reference to the distance reading of the specified sensor.
     */
    double& operator[](int index);

    /*! \brief Calculates the angle of a specific lidar sensor based on its index.
     *  \param i Index of the sensor.
     *  \return Angle of the specified lidar sensor in degrees.
     */
    double getAngle(int i) const;

    /*!
    * \brief Retrieves the distance value from a specific lidar sensor.
     * \param index The index of the lidar sensor to retrieve the value from.
    * \return The distance value recorded by the specified lidar sensor.
     * \note The index should be within the valid range [0, rangeNumber - 1].
    */
    double getSensorValue(int index) const override;
};

/*! \brief Function to test the LidarSensor class.
 *  \param lidarsensor Reference to a LidarSensor object.
 */
void LidarSensorTest(LidarSensor& lidarsensor);

#endif //LIDAR_SENSOR_H
