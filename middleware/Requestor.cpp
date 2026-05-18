#include "Requestor.h"

#include <iostream>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#include "../common/Serializer.h"

using json = nlohmann::json;

std::string Requestor::doOperation(
    RemoteObjectRef objectRef,
    std::string methodID,
    std::string arguments
) {

    // Cria request JSON
    json request;

    request["objectReference"] =
        objectRef.objectName;

    request["methodID"] =
        methodID;

    request["arguments"] =
        json::parse(arguments);

    std::string requestData =
        request.dump();

    // Cria socket
    int clientSocket =
        socket(AF_INET, SOCK_STREAM, 0);

    if(clientSocket < 0) {

        return R"({
            "status":"ERROR",
            "result":"Erro ao criar socket"
        })";
    }

    sockaddr_in serverAddress;

    serverAddress.sin_family = AF_INET;

    serverAddress.sin_port =
        htons(objectRef.port);

    inet_pton(
        AF_INET,
        objectRef.host.c_str(),
        &serverAddress.sin_addr
    );

    // Conecta ao servidor
    if(connect(
        clientSocket,
        (sockaddr*)&serverAddress,
        sizeof(serverAddress)
    ) < 0) {

        close(clientSocket);

        return R"({
            "status":"ERROR",
            "result":"Erro de conexao"
        })";
    }

    // Envia request
    send(
        clientSocket,
        requestData.c_str(),
        requestData.size(),
        0
    );

    // Recebe resposta
    char buffer[4096];

    int bytesReceived =
        recv(
            clientSocket,
            buffer,
            sizeof(buffer),
            0
        );

    if(bytesReceived < 0) {

        close(clientSocket);

        return R"({
            "status":"ERROR",
            "result":"Erro ao receber resposta"
        })";
    }

    std::string response(
        buffer,
        bytesReceived
    );

    close(clientSocket);

    return response;
}