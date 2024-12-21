#ifndef MAPPER_H
#define MAPPER_H
#ifndef M_PI
#define M_PI 3.14159265358979323846 //!< Define PI if not already defined.
#endif

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
