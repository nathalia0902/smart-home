#ifndef SMART_HOME_API_SERVICE_H
#define SMART_HOME_API_SERVICE_H

#include <map>
#include <string>
#include <nlohmann/json.hpp>

#include "../common/Entities.h"

using json = nlohmann::json;

class SmartHomeApiService {
private:
    SmartHome home;

    std::map<int, Lamp> lamps;
    std::map<int, Sensor> sensors;

public:
    SmartHomeApiService();

    json getHome();

    json listDevices();

    json getDeviceById(int deviceId);

    json turnOn(int deviceId);

    json turnOff(int deviceId);

    json getTemperature(int sensorId);

    json setBrightness(int lampId, int brightness);

    float getCurrentTemperature();

    int getCurrentLight();  

private:
    json lampToJson(const Lamp& lamp);

    json sensorToJson(const Sensor& sensor);

    bool lampExists(int lampId);

    bool sensorExists(int sensorId);
};

#endif