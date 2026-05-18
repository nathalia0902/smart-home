#include "SmartHomeServiceImpl.h"

std::string SmartHomeServiceImpl::turnOn(int deviceId) {
    return "Device turned ON";
}

std::string SmartHomeServiceImpl::turnOff(int deviceId) {
    return "Device turned OFF";
}

float SmartHomeServiceImpl::getTemperature(int sensorId) {
    return 25.7;
}

int SmartHomeServiceImpl::setBrightness(
    int lampId,
    int value
) {
    return value;
}