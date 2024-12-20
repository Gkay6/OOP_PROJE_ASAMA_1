#ifndef MAPPER_H
#define MAPPER_H
#include "LidarSensor.h"
#include "RobotController.h"
#include "MAP.h"

class Mapper
{
private:
	MAP &map;
	RobotController* controller;
	LidarSensor lidar;
public:
	Mapper(MAP& map, RobotController* controller, LidarSensor lidar);
	void updateMap();
	bool recordMap();
	void showMap();
};
#endif
