#ifndef MAPPER_H
#define MAPPER_H
#include "LidarSensor.h"
#include "RobotController.h"
#include "MAP.h"
#include "Record.h"

class Mapper
{
private:
	
	RobotController* controller;
	LidarSensor& lidar;
public:
	MAP map;
	Mapper(RobotController* controller, LidarSensor& lidar);
	void updateMap();
	bool recordMap();
	void showMap();
};
#endif
