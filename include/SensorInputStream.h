#ifndef SENSOR_INPUT_STREAM_H
#define SENSOR_INPUT_STREAM_H

#include <istream>
#include "Sensor.h"

class SensorInputStream {
private:
    std::istream& in;

public:
    SensorInputStream(std::istream& in);
    Sensor* read(int &quantidade);
};

#endif