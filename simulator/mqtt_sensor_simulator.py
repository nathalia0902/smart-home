import random
import time

import paho.mqtt.client as mqtt

broker = "localhost"

client = mqtt.Client()

client.connect(broker, 1883)

while True:

    temperature = round(
        random.uniform(23, 29),
        1
    )

    light = random.randint(
        1000,
        3000
    )

    client.publish(
        "smartHome/temperature",
        str(temperature)
    )

    client.publish(
        "smartHome/light",
        str(light)
    )

    print(
        "Temp:",
        temperature,
        "Light:",
        light
    )

    time.sleep(5)