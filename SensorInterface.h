#ifndef SENSOR_INTERFACE_H
#define SENSOR_INTERFACE_H

#include <string>

class SensorInterface {
private:
    std::string sensorType;
public:
    SensorInterface(std::string _sensorType);
    virtual ~SensorInterface() = default;
    virtual void update(int index = -1) = 0;
    std::string getSensorType() const;
    virtual double getSensorValue(int index) const = 0;
};

#endif // SENSOR_INTERFACE_H
