#include "Invoker.h"

#include <iostream>

#include "../common/Serializer.h"

using json = nlohmann::json;

Invoker::Invoker(SmartHomeService* service) {

    this->service = service;
}

std::string Invoker::invoke(
    std::string requestData
) {

    json request = json::parse(requestData);

    std::string methodID =
        request["methodID"];

    json arguments =
        request["arguments"];

    json reply;

    try {

        // turnOn
        if(methodID == "turnOn") {

            int deviceId =
                arguments["deviceId"];

            std::string result =
                service->turnOn(deviceId);

            reply["status"] = "OK";

            reply["result"] = result;
        }

        // turnOff
        else if(methodID == "turnOff") {

            int deviceId =
                arguments["deviceId"];

            std::string result =
                service->turnOff(deviceId);

            reply["status"] = "OK";

            reply["result"] = result;
        }

        // getTemperature
        else if(methodID == "getTemperature") {

            int sensorId =
                arguments["sensorId"];

            float result =
                service->getTemperature(sensorId);

            reply["status"] = "OK";

            reply["result"] = result;
        }

        // setBrightness
        else if(methodID == "setBrightness") {

            int lampId =
                arguments["lampId"];

            int value =
                arguments["value"];

            int result =
                service->setBrightness(
                    lampId,
                    value
                );

            reply["status"] = "OK";

            reply["result"] = result;
        }

        else {

            reply["status"] = "ERROR";

            reply["result"] =
                "Metodo remoto inexistente";
        }

    }
    catch(std::exception& e) {

        reply["status"] = "ERROR";

        reply["result"] = e.what();
    }

    return reply.dump();
}