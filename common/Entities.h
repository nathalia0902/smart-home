#ifndef ENTITIES_H
#define ENTITIES_H

#include <string>
#include <vector>

class Device {
public:
    int id;
    std::string name;
    bool status;
    std::string type;

    Device() {}

    Device(int id, std::string name, bool status, std::string type) {
        this->id = id;
        this->name = name;
        this->status = status;
        this->type = type;
    }
};

class Sensor : public Device {
public:
    float temperature;
    std::string unit;

    Sensor() {}

    Sensor(int id, std::string name, bool status, float temperature, std::string unit)
        : Device(id, name, status, "Sensor") {
        this->temperature = temperature;
        this->unit = unit;
    }
};

class Lamp : public Device {
public:
    int brightness;

    Lamp() {}

    Lamp(int id, std::string name, bool status, int brightness)
        : Device(id, name, status, "Lamp") {
        this->brightness = brightness;
    }
};

class Room {
public:
    int id;
    std::string name;
    std::vector<int> deviceIds;

    Room() {}

    Room(int id, std::string name, std::vector<int> deviceIds) {
        this->id = id;
        this->name = name;
        this->deviceIds = deviceIds;
    }
};

class SmartHome {
public:
    std::string name;
    std::vector<Room> rooms;

    SmartHome() {}

    SmartHome(std::string name, std::vector<Room> rooms) {
        this->name = name;
        this->rooms = rooms;
    }
};

#endif