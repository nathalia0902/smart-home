Hardware planejado para integração:

ESP32 DevKit

Sensor DHT11
- temperatura

Sensor LDR
- luminosidade

Broker MQTT

Topicos MQTT:

smartHome/temperature

smartHome/light

smartHome/lamp

O hardware será integrado utilizando
Publish-Subscribe.

Os sensores publicarão dados no Broker MQTT.

A API REST consumirá esses dados e
os disponibilizará para os clientes.