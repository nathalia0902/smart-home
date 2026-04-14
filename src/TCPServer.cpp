#include <iostream>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

using namespace std;

#define PORT 8080

int main() {
    int server_fd, client_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // Criar socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0) {
        perror("Erro ao criar socket");
        return 1;
    }

    // Configurar endereço
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; // aceita qualquer IP
    address.sin_port = htons(PORT);

    // Bind
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Erro no bind");
        return 1;
    }

    // Escutar
    if (listen(server_fd, 3) < 0) {
        perror("Erro no listen");
        return 1;
    }

    cout << "🖥️ Servidor TCP iniciado na porta " << PORT << "..." << endl;
    cout << "Aguardando conexão..." << endl;

    // Aceitar conexão
    client_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
    if (client_socket < 0) {
        perror("Erro no accept");
        return 1;
    }

    cout << "✅ Cliente conectado!" << endl;

    // RECEBER DADOS
    char buffer[1024] = {0};

    int bytes = read(client_socket, buffer, sizeof(buffer));

    if (bytes > 0) {
        cout << "📥 Dados recebidos: " << buffer << endl;
    } else {
        cout << "⚠️ Nenhum dado recebido" << endl;
    }

    close(client_socket);
    close(server_fd);

    return 0;
}