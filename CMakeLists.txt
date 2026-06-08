cmake_minimum_required(VERSION 3.10)

project(SmartHomeAPI)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(nlohmann_json REQUIRED)

include_directories(common)
include_directories(server)
include_directories(third_party)

add_executable(smart_home_api
    server/Server.cpp
    server/SmartHomeApiService.cpp
)

target_link_libraries(smart_home_api
    nlohmann_json::nlohmann_json
    pthread
)