/**
 * @file   IRSensor.h
 * @author Gokay Taspinar
 * @date   22.12.2024
 * @brief  Header file for the IRSensor class
 */

#ifndef IRSENSOR_H
#define IRSENSOR_H
#include "FestoRobotSensorInterface.h"

 /**
  * @class IRSensor
  * @brief Class to use IR sensors
  *
  * Provides methods that read sensor data and returns calculated distance values for the sensors
  */
class IRSensor : public FestoRobotSensorInterface
{
private:
	double ranges[9]; //!< Stores sensor values
	
	// FestoRobotAPI returns incorrect distance values
	// The value is used to convert the API values to actual distance
	// This value is specifically calculated for the sensor SharpGP2Y0A02YK0F
	// And it is most accurate at 0.50 meters
	const double CONVERSION_FACTOR = 4.8275; //!< This variable used to convert sensor data to distance data
public:

	//! Constructor
	IRSensor(FestoRobotAPI* robotAPI);

	double getSensorValue(int index) const override;

	//! Updates the sensor at the given index, if no index is given updates all the sensors.
	void update(int index = -1);

	//! Returns last IR sensor reading at given index
	double getRange(int index) const;
	
	//! [] operator overload, returns last IR sensor reading at given index
	double& operator[](int index);
};

#endif // IRSENSOR_H
