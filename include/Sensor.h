#ifndef SENSOR_H
#define SENSOR_H

class Sensor {
public:
    int id;
    char tipo[20];   // temperatura ou luminosidade
    float valor;
};

#endif