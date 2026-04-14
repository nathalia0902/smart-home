#include <iostream>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

using namespace std;

#define PORT 8080

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;

    cout << "Iniciando cliente..." << endl;

    // Criar socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Erro ao criar socket");
        return -1;
    }

    cout << "Socket criado!" << endl;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    //ip do server
    if (inet_pton(AF_INET, "192.168.1.112", &serv_addr.sin_addr) <= 0) {
        cout << "Erro no IP" << endl;
        return -1;
    }

    cout << "Tentando conectar..." << endl;

    // Conectar
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Erro na conexão");
        return -1;
    }

    cout << "Conectado ao servidor!" << endl;

    const char* msg = "Teste TCP funcionando!";
    send(sock, msg, strlen(msg), 0);

    cout << "Mensagem enviada!" << endl;

    close(sock);
    return 0;
}