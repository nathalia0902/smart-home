#include "Dispatcher.h"

#include <iostream>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#include "../middleware/Invoker.h"
#include "SmartHomeServiceImpl.h"

void Dispatcher::startServer() {

    int serverSocket;

    int clientSocket;

    sockaddr_in serverAddress;

    sockaddr_in clientAddress;

    socklen_t clientSize = sizeof(clientAddress);

    // Criação do socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    if(serverSocket < 0) {

        std::cout << "Erro ao criar socket"
                  << std::endl;

        return;
    }

    // Configuração do servidor
    serverAddress.sin_family = AF_INET;

    serverAddress.sin_port = htons(8080);

    serverAddress.sin_addr.s_addr = INADDR_ANY;

    // Bind
    if(bind(
        serverSocket,
        (sockaddr*)&serverAddress,
        sizeof(serverAddress)
    ) < 0) {

        std::cout << "Erro no bind"
                  << std::endl;

        return;
    }

    // Listen
    listen(serverSocket, 5);

    std::cout << "Servidor RMI iniciado na porta 8080"
              << std::endl;

    // Serviço remoto
    SmartHomeServiceImpl service;

    // Invoker
    Invoker invoker(&service);

    while(true) {

        // Aceita cliente
        clientSocket = accept(
            serverSocket,
            (sockaddr*)&clientAddress,
            &clientSize
        );

        if(clientSocket < 0) {

            std::cout << "Erro ao aceitar cliente"
                      << std::endl;

            continue;
        }

        char buffer[4096];

        int bytesReceived =
            recv(
                clientSocket,
                buffer,
                sizeof(buffer),
                0
            );

        if(bytesReceived <= 0) {

            close(clientSocket);

            continue;
        }

        // Converte para string
        std::string request(
            buffer,
            bytesReceived
        );

        std::cout << "Request recebida:"
                  << std::endl;

        std::cout << request
                  << std::endl;

        // Invoca método remoto
        std::string reply =
            invoker.invoke(request);

        // Envia resposta
        send(
            clientSocket,
            reply.c_str(),
            reply.size(),
            0
        );

        std::cout << "Reply enviada:"
                  << std::endl;

        std::cout << reply
                  << std::endl;

        close(clientSocket);
    }

    close(serverSocket);
}