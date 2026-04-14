#include <iostream>
#include "../include/SensorService.h"

using namespace std;

void SensorService::imprimirSensor(Sensor s) {
    cout << "Sensor ID: " << s.id << endl;
    cout << "Tipo: " << s.tipo << endl;
    cout << "Valor: " << s.valor << endl;
    cout << "------------------------" << endl;
}