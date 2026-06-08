#include "SmartHomeApiService.h"

SmartHomeApiService::SmartHomeApiService() {
    lamps[1] = Lamp(1, "Lâmpada da Sala", false, 60);
    lamps[2] = Lamp(2, "Lâmpada do Quarto", false, 40);

    sensors[3] = Sensor(3, "Sensor de Temperatura da Sala", true, 26.5, "Celsius");
    sensors[4] = Sensor(4, "Sensor de Temperatura do Quarto", true, 24.8, "Celsius");

    Room sala(1, "Sala", {1, 3});
    Room quarto(2, "Quarto", {2, 4});

    home = SmartHome("Smart Home Nathalia e Eduarda", {sala, quarto});
}

json SmartHomeApiService::getHome() {
    json response;

    response["name"] = home.name;
    response["rooms"] = json::array();

    for (const Room& room : home.rooms) {
        json roomJson;

        roomJson["id"] = room.id;
        roomJson["name"] = room.name;
        roomJson["deviceIds"] = room.deviceIds;

        response["rooms"].push_back(roomJson);
    }

    return response;
}

json SmartHomeApiService::listDevices() {
    json response;

    response["devices"] = json::array();

    for (const auto& item : lamps) {
        response["devices"].push_back(lampToJson(item.second));
    }

    for (const auto& item : sensors) {
        response["devices"].push_back(sensorToJson(item.second));
    }

    return response;
}

json SmartHomeApiService::getDeviceById(int deviceId) {
    if (lampExists(deviceId)) {
        return lampToJson(lamps[deviceId]);
    }

    if (sensorExists(deviceId)) {
        return sensorToJson(sensors[deviceId]);
    }

    return {
        {"status", "ERROR"},
        {"message", "Dispositivo não encontrado"}
    };
}

json SmartHomeApiService::turnOn(int deviceId) {
    if (lampExists(deviceId)) {
        lamps[deviceId].status = true;

        return {
            {"status", "OK"},
            {"message", "Lâmpada ligada com sucesso"},
            {"device", lampToJson(lamps[deviceId])}
        };
    }

    if (sensorExists(deviceId)) {
        sensors[deviceId].status = true;

        return {
            {"status", "OK"},
            {"message", "Sensor ativado com sucesso"},
            {"device", sensorToJson(sensors[deviceId])}
        };
    }

    return {
        {"status", "ERROR"},
        {"message", "Dispositivo não encontrado"}
    };
}

json SmartHomeApiService::turnOff(int deviceId) {
    if (lampExists(deviceId)) {
        lamps[deviceId].status = false;

        return {
            {"status", "OK"},
            {"message", "Lâmpada desligada com sucesso"},
            {"device", lampToJson(lamps[deviceId])}
        };
    }

    if (sensorExists(deviceId)) {
        sensors[deviceId].status = false;

        return {
            {"status", "OK"},
            {"message", "Sensor desativado com sucesso"},
            {"device", sensorToJson(sensors[deviceId])}
        };
    }

    return {
        {"status", "ERROR"},
        {"message", "Dispositivo não encontrado"}
    };
}

json SmartHomeApiService::getTemperature(int sensorId) {
    if (!sensorExists(sensorId)) {
        return {
            {"status", "ERROR"},
            {"message", "Sensor não encontrado"}
        };
    }

    return {
        {"status", "OK"},
        {"sensorId", sensorId},
        {"sensorName", sensors[sensorId].name},
        {"temperature", sensors[sensorId].temperature},
        {"unit", sensors[sensorId].unit}
    };
}

json SmartHomeApiService::setBrightness(int lampId, int brightness) {
    if (!lampExists(lampId)) {
        return {
            {"status", "ERROR"},
            {"message", "Lâmpada não encontrada"}
        };
    }

    if (brightness < 0 || brightness > 100) {
        return {
            {"status", "ERROR"},
            {"message", "O brilho deve estar entre 0 e 100"}
        };
    }

    lamps[lampId].brightness = brightness;

    return {
        {"status", "OK"},
        {"message", "Brilho alterado com sucesso"},
        {"device", lampToJson(lamps[lampId])}
    };
}

json SmartHomeApiService::lampToJson(const Lamp& lamp) {
    return {
        {"id", lamp.id},
        {"name", lamp.name},
        {"status", lamp.status},
        {"type", lamp.type},
        {"brightness", lamp.brightness}
    };
}

json SmartHomeApiService::sensorToJson(const Sensor& sensor) {
    return {
        {"id", sensor.id},
        {"name", sensor.name},
        {"status", sensor.status},
        {"type", sensor.type},
        {"temperature", sensor.temperature},
        {"unit", sensor.unit}
    };
}

bool SmartHomeApiService::lampExists(int lampId) {
    return lamps.find(lampId) != lamps.end();
}

bool SmartHomeApiService::sensorExists(int sensorId) {
    return sensors.find(sensorId) != sensors.end();
}

float SmartHomeApiService::getCurrentTemperature() {
    return 26.4;
}

int SmartHomeApiService::getCurrentLight() {
    return 1820;
}