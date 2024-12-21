#include "IRSensor.h"
#include <iostream>


// Constructor
IRSensor::IRSensor(FestoRobotAPI* _robotAPI){
	robotAPI = _robotAPI;

	// Initial sensor values
	for (int i = 0; i < 9; i++) {
		ranges[i] = INT_MAX;
	}
}


// Updates the sensor at the given index, if no index is given updates all the sensors.
void IRSensor::update(int index) {
	
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
}


// Returns last IR sensor reading at given index
double IRSensor::getRange(int index) {
	
	if (index >= 0 && index < 9) {
		return ranges[index];
	}
	else {
		std::cerr << "Invalid index\n";
	}
}


// [] operator overload, returns last IR sensor reading at given index
double& IRSensor::operator[](int index) {
	
	if (index >= 0 && index < 9) {
		return ranges[index];
	}
	else {
		std::cerr << "Invalid index\n";
	}
}