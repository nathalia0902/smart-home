#ifndef SMART_HOME_SERVICE_IMPL_H
#define SMART_HOME_SERVICE_IMPL_H

#include "SmartHomeService.h"

class SmartHomeServiceImpl
    : public SmartHomeService {

public:

    std::string turnOn(int deviceId);

    std::string turnOff(int deviceId);

    float getTemperature(int sensorId);

    int setBrightness(int lampId, int value);
};

#endif