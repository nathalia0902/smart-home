#ifndef SMART_HOME_SERVICE_H
#define SMART_HOME_SERVICE_H

#include <string>

class SmartHomeService {

public:

    virtual std::string turnOn(int deviceId) = 0;

    virtual std::string turnOff(int deviceId) = 0;

    virtual float getTemperature(int sensorId) = 0;

    virtual int setBrightness(int lampId, int value) = 0;
};

#endif