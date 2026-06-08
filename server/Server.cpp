#include <iostream>
#include <string>

#include "httplib.h"
#include "SmartHomeApiService.h"

using namespace httplib;

void setJsonResponse(Response& res, const json& data, int statusCode = 200) {
    res.status = statusCode;
    res.set_content(data.dump(4), "application/json");
}

int main() {
    Server server;

    SmartHomeApiService service;

    server.Get("/api/health", [](const Request& req, Response& res) {
        json response = {
            {"status", "OK"},
            {"message", "Smart Home API está funcionando"}
        };

        setJsonResponse(res, response);
    });

    server.Get("/api/home", [&](const Request& req, Response& res) {
        setJsonResponse(res, service.getHome());
    });

    server.Get("/api/devices", [&](const Request& req, Response& res) {
        setJsonResponse(res, service.listDevices());
    });

    server.Get(R"(/api/devices/(\d+))", [&](const Request& req, Response& res) {
        int deviceId = std::stoi(req.matches[1]);

        json response = service.getDeviceById(deviceId);

        if (response.contains("status") && response["status"] == "ERROR") {
            setJsonResponse(res, response, 404);
        } else {
            setJsonResponse(res, response);
        }
    });

    server.Post(R"(/api/devices/(\d+)/on)", [&](const Request& req, Response& res) {
        int deviceId = std::stoi(req.matches[1]);

        json response = service.turnOn(deviceId);

        if (response["status"] == "ERROR") {
            setJsonResponse(res, response, 404);
        } else {
            setJsonResponse(res, response);
        }
    });

    server.Post(R"(/api/devices/(\d+)/off)", [&](const Request& req, Response& res) {
        int deviceId = std::stoi(req.matches[1]);

        json response = service.turnOff(deviceId);

        if (response["status"] == "ERROR") {
            setJsonResponse(res, response, 404);
        } else {
            setJsonResponse(res, response);
        }
    });

    server.Get(R"(/api/sensors/(\d+)/temperature)", [&](const Request& req, Response& res) {
        int sensorId = std::stoi(req.matches[1]);

        json response = service.getTemperature(sensorId);

        if (response["status"] == "ERROR") {
            setJsonResponse(res, response, 404);
        } else {
            setJsonResponse(res, response);
        }
    });

    server.Put(R"(/api/lamps/(\d+)/brightness)", [&](const Request& req, Response& res) {
        int lampId = std::stoi(req.matches[1]);

        try {
            json body = json::parse(req.body);

            if (!body.contains("brightness")) {
                json response = {
                    {"status", "ERROR"},
                    {"message", "Campo brightness é obrigatório"}
                };

                setJsonResponse(res, response, 400);
                return;
            }

            int brightness = body["brightness"];

            json response = service.setBrightness(lampId, brightness);

            if (response["status"] == "ERROR") {
                setJsonResponse(res, response, 400);
            } else {
                setJsonResponse(res, response);
            }

        } catch (...) {
            json response = {
                {"status", "ERROR"},
                {"message", "JSON inválido"}
            };

            setJsonResponse(res, response, 400);
        }
    });

    server.Get("/api/sensors/temperature",
        [&](const Request& req, Response& res)
        {
            json response;

            response["temperature"] =
                service.getCurrentTemperature();

            response["unit"] = "Celsius";

            res.set_content(
                response.dump(4),
                "application/json"
            );
        });

    server.Get("/api/sensors/light",
        [&](const Request& req, Response& res)
        {
            json response;

            response["light"] =
                service.getCurrentLight();

            response["unit"] = "lux";

            res.set_content(
                response.dump(4),
                "application/json"
            );
        });

    server.set_logger([](const Request& req, const Response& res) {
        std::cout << req.method << " " << req.path
                  << " -> " << res.status << std::endl;
    });

    std::cout << "======================================" << std::endl;
    std::cout << " Smart Home API iniciada com sucesso" << std::endl;
    std::cout << " URL: http://localhost:8080/api/health" << std::endl;
    std::cout << "======================================" << std::endl;

    server.listen("0.0.0.0", 8080);

    return 0;
}