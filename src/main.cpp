#include <iostream>
#include <fstream>
#include <cstring>

#include "../include/Sensor.h"
#include "../include/SensorService.h"
#include "../include/MonitoramentoService.h"
#include "../include/SensorOutputStream.h"
#include "../include/SensorInputStream.h"

using namespace std;

int main() {
    cout << "Smart Home iniciado..." << endl;

    // Criando sensores
    Sensor sensores[2];

    sensores[0].id = 1;
    strcpy(sensores[0].tipo, "temperatura");
    sensores[0].valor = 32.5;

    sensores[1].id = 2;
    strcpy(sensores[1].tipo, "luminosidade");
    sensores[1].valor = 80;

    // Services
    SensorService sensorService;
    MonitoramentoService monitoramentoService;

    cout << "\n--- TESTE CONSOLE ---" << endl;

    for (int i = 0; i < 2; i++) {
        sensorService.imprimirSensor(sensores[i]);
        monitoramentoService.verificarAlerta(sensores[i]);
    }

    // ==========================
    // TESTE COM ARQUIVO
    // ==========================

    cout << "\n--- TESTE ARQUIVO ---" << endl;

    ofstream arquivoOut("sensores.bin", ios::binary);
    SensorOutputStream sos(sensores, 2, arquivoOut);
    sos.write();
    arquivoOut.close();

    ifstream arquivoIn("sensores.bin", ios::binary);
    SensorInputStream sis(arquivoIn);

    int quantidade;
    Sensor* sensoresLidos = sis.read(quantidade);

    cout << "Sensores lidos do arquivo:\n";

    for (int i = 0; i < quantidade; i++) {
        sensorService.imprimirSensor(sensoresLidos[i]);
    }

    delete[] sensoresLidos;

    cout << "\nFinalizado!" << endl;

    return 0;
}