/**
 * @file   IRSensor.cpp
 * @author Gokay Taspinar
 * @date   22.12.2024
 * @brief  Implementation of the IRSensor class methods
 */

#include "IRSensor.h"
#include <iostream>


// Constructor
IRSensor::IRSensor(FestoRobotAPI* _robotAPI)
    : FestoRobotSensorInterface(_robotAPI)
{
	// Initial sensor values
	for (int i = 0; i < 9; i++) {
		ranges[i] = INT_MAX;
	}
}


// Updates the sensor at the given index, if no index is given updates all the sensors.
void IRSensor::update(int index)override {
	
	if (index == -1) {
		// Update all sensors
		for (int i = 0; i < 9; i++) {
			ranges[i] = robotAPI->getIRRange(i) * CONVERSION_FACTOR;
		}
	}
	else if (index >= 0 && index < 9) {
		// Update single sensor
		ranges[index] = robotAPI->getIRRange(index) * CONVERSION_FACTOR;
	}
	else {
        std::cerr << "IRSensor::update error, invalid index!" << std::endl;
        }
}


// Returns last IR sensor reading at given index
/*!
 * \return last IR sensor reading at given index
 */
double IRSensor::getRange(int index) {
	
	if (index >= 0 && index < 9) {
		return ranges[index];
	}
	else {
		std::cerr << "Invalid index\n";
		return -1.0;
	}
}


// [] operator overload, returns last IR sensor reading at given index
/*!
 * \return last IR sensor reading at given index
 */
double& IRSensor::operator[](int index) {
	
	if (index >= 0 && index < 9) {
		return ranges[index];
	}
	else {
		std::cerr << "Invalid index\n";
		static double error_value = -1.0;
        	return error_value;
	}
}


double IRSensor::getSensorValue(int index) const {
    if (index >= 0 && index < 9) {
        return ranges[index];
    }
    else {
        std::cerr << "Invalid index in getSensorValue\n";
        return -1.0;
    }
}
