#include "LidarSensor.h"
#include <iostream>
LidarSensor::LidarSensor(FestoRobotAPI* _robotAPI)
	:robotAPI(_robotAPI)
{
	this->rangeNumber = this->robotAPI->getLidarRangeNumber();
	this->ranges = new double[this->rangeNumber];
}

double LidarSensor::getRange(int index) const
{
	return this->ranges[index];
}

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

void LidarSensor::update() const
{
	//int number = this->robotAPI->getLidarRangeNumber();

	//float* ranges = new float[number];
	std::cout << "--------------------LIDAR VALUES (in meters)-------------------------------------" << endl;
	float* temp_ranges = new float[this->rangeNumber];

	this->robotAPI->getLidarRange(temp_ranges);
	for (int i = 0; i < this->rangeNumber; i++)
	{
		this->ranges[i] = (double)temp_ranges[i];
	}
	delete[] temp_ranges;
	for (int i = 0; i < this->rangeNumber; i++) 
	{
		std::cout << i << "-> ";
		std::cout << this->getRange(i) << endl;
	}
	
	std::cout << "----------------------------------------------------------------------" << endl;
}

double& LidarSensor::operator[](int index)
{
	if (index < this->robotAPI->getLidarRangeNumber())
	{
		return this->ranges[index];
	}
	else
	{
		std::cerr << "LidarSensor::operator[] error, out of boundaries! " << std::endl;
		exit(0);
	}
}

double LidarSensor::getAngle(int i) const
{
	return 120 - 0.36 * i;
}

LidarSensor::~LidarSensor()
{
	std::cout << "~LidarSensor start" << std::endl;
	delete[] this->ranges;
	std::cout << "~LidarSensor end" << std::endl;
}
