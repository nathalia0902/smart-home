#ifndef MQTT_SUBSCRIBER_H
#define MQTT_SUBSCRIBER_H

class MQTTSubscriber
{
public:

    float temperature;

    int light;

    MQTTSubscriber();

    void start();
};

#endif