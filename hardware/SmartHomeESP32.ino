#include <WiFi.h>
#include <PubSubClient.h>

#include <DHT.h>

#include "wifi_config.h"

#define DHTPIN 4
#define DHTTYPE DHT11

#define LDR_PIN 34

WiFiClient espClient;

PubSubClient client(espClient);

DHT dht(DHTPIN, DHTTYPE);

void connectWiFi()
{
    WiFi.begin(
        WIFI_SSID,
        WIFI_PASSWORD
    );

    while(WiFi.status() != WL_CONNECTED)
    {
        delay(500);
    }
}

void reconnect()
{
    while(!client.connected())
    {
        client.connect(
            "ESP32SmartHome"
        );
    }
}

void setup()
{
    Serial.begin(115200);

    dht.begin();

    connectWiFi();

    client.setServer(
        MQTT_SERVER,
        MQTT_PORT
    );
}

void loop()
{
    if(!client.connected())
    {
        reconnect();
    }

    client.loop();

    float temperature =
        dht.readTemperature();

    int light =
        analogRead(LDR_PIN);

    client.publish(
        "smartHome/temperature",
        String(temperature).c_str()
    );

    client.publish(
        "smartHome/light",
        String(light).c_str()
    );

    Serial.print("Temp: ");
    Serial.print(temperature);

    Serial.print(" Light: ");
    Serial.println(light);

    delay(5000);
}