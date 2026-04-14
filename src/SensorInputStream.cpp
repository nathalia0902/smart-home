#include "../include/SensorInputStream.h"

SensorInputStream::SensorInputStream(std::istream& in) : in(in) {}

Sensor* SensorInputStream::read(int &quantidade) {
    in.read((char*)&quantidade, sizeof(int));

    Sensor* sensores = new Sensor[quantidade];

    for (int i = 0; i < quantidade; i++) {
        in.read((char*)&sensores[i].id, sizeof(int));
        in.read(sensores[i].tipo, sizeof(sensores[i].tipo));
        in.read((char*)&sensores[i].valor, sizeof(float));
    }

    return sensores;
}