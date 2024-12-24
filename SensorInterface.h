#ifndef SENSOR_INTERFACE_H
#define SENSOR_INTERFACE_H

#include <string>

class SensorInterface {
public:
    virtual ~SensorInterface() = default;
    
    virtual std::string getSensorType() const = 0;
    virtual double getSensorValue(int index) const = 0;
    virtual void update(int index = -1) = 0;
};

#endif // SENSOR_INTERFACE_H
