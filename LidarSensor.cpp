/*!
 * \file LidarSensor.cpp
 * \author Utku Buðra Namkazan
 * \date 22.12.2024
 * \brief Implementation file for the LidarSensor class, which gets data from lidar sensors from the robot using the FestoRobotAPI.
 */
#include "LidarSensor.h"
#define degree_diff 0.3603603603603604 //!< Angular difference between consecutive sensors. 
#include <iostream>

// Constructor
/*! 
 * \brief Constructor implementation for the LidarSensor class. 
 */
LidarSensor::LidarSensor(FestoRobotAPI* _robotAPI)
	:robotAPI(_robotAPI)
{
	this->rangeNumber = this->robotAPI->getLidarRangeNumber();
	this->ranges = new double[this->rangeNumber];
	float* temp_ranges = new float[this->rangeNumber];
	this->robotAPI->getLidarRange(temp_ranges);
	for (int i = 0; i < this->rangeNumber; i++)
	{
		this->ranges[i] = (double)temp_ranges[i];
	}
	delete[] temp_ranges;
}

// Destructor
/*! 
 *\brief Destructor implementation for the LidarSensor class.
 */
LidarSensor::~LidarSensor()
{
	delete[] this->ranges;
}

// Retrieve the number of lidar sensors
/*!
 * \brief Retrieves the number of lidar sensors on the robot.
 */
int LidarSensor::getRangeNumber() const
{
	return this->rangeNumber;
}

// Retrieve distance reading from a specific lidar sensor
/*!
 *\brief Retrieves the distance reading from a specific lidar sensor. 
 */
double LidarSensor::getRange(int index) const
{
	if (index < this->rangeNumber)
	{
		return this->ranges[index];
	}
	else
	{
		std::cerr << "LidarSensor::getRange(int) error, out of boundaries! " << std::endl;
		exit(0);
	}
}

// Retrieve the maximum distance value and its index
/*! 
 *\brief Retrieves the maximum distance value and its index.
 */
double LidarSensor::getMax(int& index) const
{
	double max_value = ranges[0];
	for (int i = 0; i < this->robotAPI->getLidarRangeNumber(); i++)
	{
		if (max_value < ranges[i])
		{
			max_value = ranges[i];
			index = i;
		}
	}
	return max_value;
}

// Retrieve the minimum distance value and its index
/*! 
 *\brief Retrieves the minimum distance value and its index. 
 */
double LidarSensor::getMin(int& index) const
{
	double min_value = ranges[0];
	for (int i = 0; i < this->robotAPI->getLidarRangeNumber(); i++)
	{
		if (min_value > ranges[i])
		{
			min_value = ranges[i];
			index = i;
		}
	}
	return min_value;
}

// Update lidar sensor readings
/*! 
 *\brief Updates the lidar sensor readings and prints them to the console.
 */
void LidarSensor::update() const
{
	float* temp_ranges = new float[this->rangeNumber];
	this->robotAPI->getLidarRange(temp_ranges);
	for (int i = 0; i < this->rangeNumber; i++)
	{
		this->ranges[i] = (double)temp_ranges[i];
	}
	delete[] temp_ranges;	
}

// Access operator implementation
/*!
 *\brief Access operator implementation.
 */
double& LidarSensor::operator[](int index)
{
	if (index < this->rangeNumber)
	{
		return this->ranges[index];
	}
	else
	{
		std::cerr << "LidarSensor::operator[] error, out of boundaries! " << std::endl;
		exit(0);
	}
}
// Calculate the angle of a specific lidar sensor
/*!
 * \brief Calculates the angle of a specific lidar sensor.
 */
double LidarSensor::getAngle(int i) const
{
	return 120 - degree_diff * i;
}


