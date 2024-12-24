#ifndef FESTO_ROBOT_SENSOR_INTERFACE_H
#define FESTO_ROBOT_SENSOR_INTERFACE_H

#include "SensorInterface.h"
#include "FestoRobotAPI.h"

class FestoRobotSensorInterface : public SensorInterface {
protected:
    FestoRobotAPI* robotAPI;

public:
    explicit FestoRobotSensorInterface(FestoRobotAPI* _robotAPI) : robotAPI(_robotAPI) {}
    virtual ~FestoRobotSensorInterface() = default;
};

#endif // FESTO_ROBOT_SENSOR_INTERFACE_H
