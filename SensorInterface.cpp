#include "SensorInterface.h"

SensorInterface::SensorInterface(std::string _sensorType)
    :sensorType(_sensorType)
{
}

std::string SensorInterface::getSensorType() const
{
    return this->sensorType;
}
