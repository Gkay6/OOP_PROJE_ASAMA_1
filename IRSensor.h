#ifndef IRSENSOR_H
#define IRSENSOR_H
#include "FestoRobotAPI.h"


class IRSensor
{
private:
	double ranges[9]; // Stores sensor values
	FestoRobotAPI* robotAPI; // Robot API
	
	// FestoRobotAPI returns incorrect distance values
	// The value is used to convert the API values to actual distance
	// This value is specifically calculated for the sensor SharpGP2Y0A02YK0F
	// And it is most accurate at 0.50 meters
	const double CONVERSION_FACTOR = 4.8275;
public:

	// Constructor
	IRSensor(FestoRobotAPI* robotAPI);
	
	// Updates the sensor at the given index, if no index is given updates all the sensors.
	void update(int index = -1);

	// Returns last IR sensor reading at given index
	double getRange(int index);
	
	// [] operator overload, returns last IR sensor reading at given index
	double& operator[](int index);
};

#endif // IRSENSOR_H