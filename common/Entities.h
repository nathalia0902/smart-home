#ifndef ENTITIES_H
#define ENTITIES_H

#include <string>
#include <vector>

class Device {
public:
    int id;
    std::string name;
    bool status;
};

class Sensor : public Device {
public:
    float temperature;
};

class Lamp : public Device {
public:
    int brightness;
};

class Room {
public:
    std::string name;
    std::vector<Device*> devices;
};

class SmartHome {
public:
    std::vector<Room> rooms;
};

#endif