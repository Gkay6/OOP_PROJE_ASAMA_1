#include <iostream>
#include "LidarSensor.h"

// Test function for LidarSensor
/*!
 *\brief Test function implementation for the LidarSensor class. 
 */
void LidarSensorTest(LidarSensor &lidarsensor)
{
	lidarsensor.update();
	std::cout << "--------------------LIDAR VALUES (in meters)-------------------------------------" << endl;
	for (int i = 0; i < lidarsensor.getRangeNumber(); i++)
	{
		std::cout << i << "-> " << lidarsensor.getRange(i) << " " << lidarsensor.getAngle(i) << " degrees" << std::endl;
	}
	std::cout << std::endl << "getMin() Test : " << std::endl;
	int index = 0;
	std::cout << lidarsensor.getMin(index) << ", number " << index << " sensor." << std::endl;
	std::cout << std::endl << "getMax() Test : " << std::endl;
	index = 0;
	std::cout << lidarsensor.getMax(index) << ", number " << index << " sensor." << std::endl;
	std::cout << std::endl << "opertator[] Test : " << std::endl;
	std::cout << "opertator[0] = " << lidarsensor[0] << std::endl;
	std::cout << "opertator[1] = " << lidarsensor[0] << std::endl;
	std::cout << "opertator[2] = " << lidarsensor[0] << std::endl;
	std::cout << "----------------------------------------------------------------------" << endl;
}