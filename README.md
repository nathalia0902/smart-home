# Smart Home API + MQTT

## Trabalho 3 – API REST

## Trabalho 4 – Comunicação Indireta com MQTT

### Integrantes

* Maria Eduarda Almeida Rodrigues
* Nathalia de Oliveira Lima

---

# 1. Visão Geral do Projeto

O projeto Smart Home simula uma residência inteligente composta por sensores e dispositivos controláveis remotamente.

A aplicação foi desenvolvida em C++ e evoluiu ao longo dos trabalhos da disciplina.

No Trabalho 3 implementamos um serviço remoto utilizando API REST.

No Trabalho 4 evoluímos a arquitetura utilizando comunicação indireta através do padrão Publish-Subscribe com MQTT.

---

# 2. O que é um Serviço Remoto?

Um serviço remoto é uma funcionalidade executada em outro processo ou computador e acessada através da rede.

Neste projeto, o servidor disponibiliza operações que podem ser acessadas remotamente pelos clientes.

Exemplos:

* Consultar dispositivos.
* Ligar uma lâmpada.
* Desligar uma lâmpada.
* Consultar temperatura.

O cliente envia uma requisição pela rede e o servidor retorna uma resposta.

---

# 3. O que é uma API REST?

API REST é uma forma de comunicação cliente-servidor baseada em HTTP.

Utilizamos:

* Requisições HTTP.
* Respostas em JSON.
* Endpoints REST.

Exemplo:

GET /api/devices

Retorna a lista de dispositivos cadastrados.

---

Os métodos disponibilizados remotamente são:

* getHome()
* listDevices()
* getDeviceById()
* turnOn()
* turnOff()
* getTemperature()
* setBrightness()

Esses métodos são acessados através dos endpoints HTTP.

---

# 4. Entidades do Sistema

## SmartHome

Representa toda a residência.

Possui vários cômodos.

---

## Room

Representa um cômodo.

Exemplos:

* Sala
* Quarto

---

## Device

Classe base para todos os dispositivos.

---

## Lamp

Representa uma lâmpada inteligente.

Herda de Device.

Possui:

* Status
* Brilho

---

## Sensor

Representa um sensor.

Herda de Device.

Possui:

* Temperatura
* Unidade de medida

---

# 5. Relacionamentos

## Agregação

Uma SmartHome possui vários Rooms.

Um Room possui vários Devices.

---

## Herança

Lamp é um Device.

Sensor é um Device.

---

# 6. Arquitetura do Trabalho 3

Cliente Python
↓
API REST (C++)
↓
Smart Home

Cliente JavaScript
↓
API REST (C++)
↓
Smart Home

---

# 7. Linguagens Utilizadas

Servidor:

C++

Cliente 1:

Python

Cliente 2:

JavaScript

Assim atendemos ao requisito de possuir pelo menos duas linguagens diferentes da linguagem utilizada pelo serviço.

---

# 8. Endpoints Disponíveis

## Verificar API

GET

/api/health

---

## Informações da Casa

GET

/api/home

---

## Listar Dispositivos

GET

/ api/devices

---

## Buscar Dispositivo

GET

/api/devices/{id}

---

## Ligar Dispositivo

POST

/api/devices/{id}/on

---

## Desligar Dispositivo

POST

/api/devices/{id}/off

---

## Alterar Brilho

PUT

/api/lamps/{id}/brightness

---

## Consultar Temperatura

GET

/api/sensors/{id}/temperature

---

# 9. Trabalho 4 – Comunicação Indireta

Neste trabalho evoluímos a arquitetura.

Escolhemos a opção:

Publish-Subscribe.

---

# 10. O que é Publish-Subscribe?

Publish-Subscribe é um modelo onde produtores e consumidores não se comunicam diretamente.

Existe um intermediário chamado Broker.

O produtor publica mensagens.

O Broker recebe as mensagens.

Os consumidores recebem as mensagens do Broker.

---

# 11. Broker Utilizado

Utilizamos o Mosquitto MQTT.

O Mosquitto é responsável por:

* Receber mensagens.
* Armazenar sessões.
* Distribuir eventos.
* Encaminhar mensagens aos assinantes.

---

# 12. Arquitetura MQTT

Publicador
↓
Broker MQTT (Mosquitto)
↓
Subscriber

---

# 13. O que é MQTT?

MQTT é um protocolo leve muito utilizado em IoT.

Ele trabalha com tópicos.

Exemplos:

smartHome/temperature

smartHome/light

---

# 14. Publicador

O publicador gera eventos de sensores.

Atualmente utilizamos:

simulator/mqtt_sensor_simulator.py

---


# 15. Como a ESP32 Funcionaria?

ESP32
↓
Leitura dos sensores
↓
Publicação MQTT
↓
Broker Mosquitto
↓
Subscribers

O simulador substitui temporariamente apenas a etapa de leitura física.

---

# 16. Onde Está o Desacoplamento?

O publicador não conhece os consumidores.

Os consumidores não conhecem o publicador.

Ambos conhecem apenas o Broker.

Essa característica é chamada de desacoplamento espacial.

---

# 17. Como Demonstramos o Desacoplamento?

Executamos:

1. Subscriber MQTT.
2. Publicador MQTT.

As mensagens são recebidas normalmente.

Depois encerramos o Subscriber.

O Publicador continua funcionando.

Isso demonstra que ele não depende diretamente dos consumidores.

---

# 18. O que o Broker Resolve?

Sem Broker:

Produtor → Consumidor

Com Broker:

Produtor → Broker → Consumidor

O Broker reduz o acoplamento e facilita a escalabilidade.
