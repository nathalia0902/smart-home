#ifndef SMART_HOME_PROXY_H
#define SMART_HOME_PROXY_H

#include <string>

#include "../middleware/Requestor.h"
#include "../common/RemoteObjectRef.h"

class SmartHomeProxy {

private:

    Requestor requestor;

    RemoteObjectRef remoteRef;

public:

    SmartHomeProxy();

    std::string turnOn(int deviceId);

    std::string turnOff(int deviceId);

    float getTemperature(int sensorId);

    int setBrightness(int lampId, int value);
};

#endif