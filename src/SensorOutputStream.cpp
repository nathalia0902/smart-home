#include "../include/SensorOutputStream.h"
#include <cstring>

SensorOutputStream::SensorOutputStream(Sensor* sensores, int quantidade, std::ostream& out)
    : sensores(sensores), quantidade(quantidade), out(out) {}

void SensorOutputStream::write() {
    out.write((char*)&quantidade, sizeof(int));

    for (int i = 0; i < quantidade; i++) {
        out.write((char*)&sensores[i].id, sizeof(int));
        out.write(sensores[i].tipo, sizeof(sensores[i].tipo));
        out.write((char*)&sensores[i].valor, sizeof(float));
    }
}