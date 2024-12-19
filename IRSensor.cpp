#include "IRSensor.h"
#include <iostream>

IRSensor::IRSensor(FestoRobotAPI* _robotAPI){
	robotAPI = _robotAPI;

	for (int i = 0; i < 9; i++) {
		ranges[i] = robotAPI->getIRRange(i) * CONVERSION_FACTOR;
	}
}

void IRSensor::update(int index) {
	//Read IR range values

	if (index == -1) {
		for (int i = 0; i < 9; i++) {
			ranges[i] = robotAPI->getIRRange(i) * CONVERSION_FACTOR;
		}
	}
	else if (index >= 0 && index < 9) {
		ranges[index] = robotAPI->getIRRange(index) * CONVERSION_FACTOR;
	}
}

double IRSensor::getRange(int index) {
	if (index >= 0 && index < 9) {
		return ranges[index];
	}
	else {
		std::cerr << "Invalid index\n";
	}
}

double& IRSensor::operator[](int index) {
	if (index >= 0 && index < 9) {
		return ranges[index];
	}
	else {
		std::cerr << "Invalid index\n";
	}
}
