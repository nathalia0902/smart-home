#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>

using namespace std;

#define MULTICAST_IP "239.0.0.1"
#define PORT 12345

int main() {
    int sock;
    struct sockaddr_in addr;

    sock = socket(AF_INET, SOCK_DGRAM, 0);

    if (sock < 0) {
        perror("Erro ao criar socket");
        return 1;
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("IP_DO_CLIENTE");
    addr.sin_port = htons(PORT);

    cout << "Servidor UDP multicast iniciado..." << endl;

    while (true) {
        string mensagem;

        cout << "Digite um alerta: ";
        getline(cin, mensagem);

        sendto(sock, mensagem.c_str(), mensagem.size(), 0,
               (struct sockaddr*)&addr, sizeof(addr));
    }

    close(sock);
    return 0;
}