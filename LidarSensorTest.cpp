#include <iostream>
#include "LidarSensor.h"


void LidarSensorTest(LidarSensor &lidarsensor)
{
	std::cout << "LidarSensorTest-start" << std::endl;
	lidarsensor.update();
	std::cout << "LidarSensorTest-end" << std::endl;
}