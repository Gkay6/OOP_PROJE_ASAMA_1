#ifndef LIDAR_SENSOR_H
#define LIDAR_SENSOR_H
#include "FestoRobotAPI.h"

class LidarSensor
{
private:
	double* ranges;
	FestoRobotAPI* robotAPI;	
	int rangeNumber;
public:	
	LidarSensor(FestoRobotAPI* _robotAPI);
	int getRangeNumber() const;
	double getRange(int index) const;
	double getMax(int& index) const;
	double getMin(int& index) const;
	void update() const;
	double& operator[](int index);
	double getAngle(int i) const;
	~LidarSensor();
};

void LidarSensorTest(LidarSensor &lidarsensor);
	
#endif