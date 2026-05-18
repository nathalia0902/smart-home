#include "SmartHomeProxy.h"

#include <iostream>

#include "../common/Serializer.h"

using json = nlohmann::json;

SmartHomeProxy::SmartHomeProxy() {

    remoteRef.host = "127.0.0.1";

    remoteRef.port = 8080;

    remoteRef.objectName = "SmartHomeService";
}

std::string SmartHomeProxy::turnOn(int deviceId) {

    json args;

    args["deviceId"] = deviceId;

    std::string response =
        requestor.doOperation(
            remoteRef,
            "turnOn",
            args.dump()
        );

    json reply = json::parse(response);

    return reply["result"];
}

std::string SmartHomeProxy::turnOff(int deviceId) {

    json args;

    args["deviceId"] = deviceId;

    std::string response =
        requestor.doOperation(
            remoteRef,
            "turnOff",
            args.dump()
        );

    json reply = json::parse(response);

    return reply["result"];
}

float SmartHomeProxy::getTemperature(int sensorId) {

    json args;

    args["sensorId"] = sensorId;

    std::string response =
        requestor.doOperation(
            remoteRef,
            "getTemperature",
            args.dump()
        );

    json reply = json::parse(response);

    return reply["result"];
}

int SmartHomeProxy::setBrightness(
    int lampId,
    int value
) {

    json args;

    args["lampId"] = lampId;

    args["value"] = value;

    std::string response =
        requestor.doOperation(
            remoteRef,
            "setBrightness",
            args.dump()
        );

    json reply = json::parse(response);

    return reply["result"];
}