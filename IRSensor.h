#ifndef IRSENSOR_H
#define IRSENSOR_H
#include "FestoRobotAPI.h"

class IRSensor
{
private:
	double ranges[9];
	FestoRobotAPI* robotAPI;
	const double CONVERSION_FACTOR = 4.7619;
public:
	IRSensor(FestoRobotAPI* robotAPI);
	void update(int index = -1);
	double getRange(int index);
	double& operator[](int index);
};

#endif // IRSENSOR_H