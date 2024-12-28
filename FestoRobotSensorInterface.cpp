#include "FestoRobotSensorInterface.h"

FestoRobotSensorInterface::FestoRobotSensorInterface(FestoRobotAPI* _robotAPI, std::string _sensorType)
	:robotAPI(_robotAPI), SensorInterface(_sensorType)
{
}
