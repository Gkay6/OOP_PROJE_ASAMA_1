#ifndef FESTO_ROBOT_SENSOR_INTERFACE_H
#define FESTO_ROBOT_SENSOR_INTERFACE_H

#include "SensorInterface.h"
#include "FestoRobotAPI.h"

class FestoRobotSensorInterface : public SensorInterface {
protected:
    FestoRobotAPI* robotAPI;

public:
    FestoRobotSensorInterface(FestoRobotAPI* _robotAPI, std::string _sensorType);
    virtual ~FestoRobotSensorInterface() = default;
};

#endif // FESTO_ROBOT_SENSOR_INTERFACE_H
