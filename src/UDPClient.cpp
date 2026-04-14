#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>

using namespace std;

#define SERVER_IP "10.10.245.60"
#define PORT 12345

int main() {
    int sock;
    struct sockaddr_in addr;
    struct ip_mreq mreq;

    sock = socket(AF_INET, SOCK_DGRAM, 0);

    if (sock < 0) {
        perror("Erro ao criar socket");
        return 1;
    }

    int reuse = 1;
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, (char *)&reuse, sizeof(reuse));

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(PORT);

    if (bind(sock, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("Erro no bind");
        return 1;
    }

    mreq.imr_multiaddr.s_addr = inet_addr(SERVER_IP);
    mreq.imr_interface.s_addr = htonl(INADDR_ANY);

    setsockopt(sock, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mreq, sizeof(mreq));

    cout << "Cliente conectado ao grupo multicast..." << endl;

    char buffer[1024];

    while (true) {
        int n = recvfrom(sock, buffer, sizeof(buffer), 0, NULL, 0);

        if (n > 0) {
            buffer[n] = '\0';
            cout << "📢 Alerta recebido: " << buffer << endl;
        }
    }

    close(sock);
    return 0;
}