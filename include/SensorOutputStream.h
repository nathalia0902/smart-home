#ifndef SENSOR_OUTPUT_STREAM_H
#define SENSOR_OUTPUT_STREAM_H

#include <ostream>
#include "Sensor.h"

class SensorOutputStream {
private:
    Sensor* sensores;
    int quantidade;
    std::ostream& out;

public:
    SensorOutputStream(Sensor* sensores, int quantidade, std::ostream& out);
    void write();
};

#endif