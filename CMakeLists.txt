cmake_minimum_required(VERSION 3.10)

project(SmartHomeRMI)

set(CMAKE_CXX_STANDARD 17)

# Biblioteca JSON
find_package(nlohmann_json REQUIRED)

# =========================
# SERVIDOR
# =========================

add_executable(server

    server/Server.cpp
    server/Dispatcher.cpp

    server/SmartHomeServiceImpl.cpp

    middleware/Invoker.cpp

    common/Serializer.cpp
)

target_link_libraries(server
    nlohmann_json::nlohmann_json
)

# =========================
# CLIENTE
# =========================

add_executable(client

    client/Client.cpp
    client/SmartHomeProxy.cpp

    middleware/Requestor.cpp

    common/Serializer.cpp
)

target_link_libraries(client
    nlohmann_json::nlohmann_json
)