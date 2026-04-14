#include <iostream>
#include <string.h>
#include "../include/MonitoramentoService.h"

using namespace std;

void MonitoramentoService::verificarAlerta(Sensor s) {
    if (strcmp(s.tipo, "temperatura") == 0 && s.valor > 30) {
        cout << "Alerta: Temperatura alta!" << endl;
    }

    if (strcmp(s.tipo, "luminosidade") == 0 && s.valor < 100) {
        cout << "Alerta: Ambiente escuro!" << endl;
    }
}