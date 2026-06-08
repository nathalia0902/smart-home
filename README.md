# Smart Home API + MQTT

## Disciplina

Sistemas Distribuídos

## Integrantes

* Nathalia de Oliveira Lima
* Maria Eduarda Almeida Rodrigues

---

# Visão Geral do Projeto

O projeto Smart Home simula uma residência inteligente composta por sensores e dispositivos controláveis remotamente.

A aplicação foi desenvolvida em C++ e evoluiu ao longo dos trabalhos da disciplina.

No Trabalho 3 implementamos um serviço remoto utilizando API REST.

No Trabalho 4 evoluímos a arquitetura utilizando comunicação indireta através do padrão Publish-Subscribe com MQTT.

---

# Entidades do Sistema

O sistema possui as seguintes entidades:

## SmartHome

Representa toda a residência inteligente.

## Room

Representa um cômodo da casa.

## Device

Classe base para dispositivos.

## Lamp

Representa uma lâmpada inteligente.

Herda de Device.

## Sensor

Representa um sensor de temperatura.

Herda de Device.

---

# Relacionamentos

## Agregação

Uma SmartHome possui vários Rooms.

Um Room possui vários Devices.

## Herança

Lamp é um Device.

Sensor é um Device.

---

# Trabalho 3 – API REST

## Objetivo

Implementar um serviço remoto sem utilizar sockets diretamente nem RMI.

A comunicação cliente-servidor foi implementada através de uma API REST.

---

# Arquitetura

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

# Endpoints Disponíveis

## Verificar API

GET

/api/health

---

## Obter informações da casa

GET

/api/home

---

## Listar dispositivos

GET

/api/devices

---

## Buscar dispositivo por ID

GET

/api/devices/{id}

---

## Ligar dispositivo

POST

/api/devices/{id}/on

---

## Desligar dispositivo

POST

/api/devices/{id}/off

---

## Alterar brilho da lâmpada

PUT

/api/lamps/{id}/brightness

---

## Consultar temperatura

GET

/api/sensors/{id}/temperature

---

# Clientes

Foram implementados dois clientes:

## Cliente Python

Realiza requisições HTTP para a API.

## Cliente JavaScript

Realiza requisições HTTP utilizando Node.js.

---

# Trabalho 4 – Comunicação Indireta

## Objetivo

Reduzir o acoplamento entre os componentes utilizando comunicação indireta.

Foi escolhido o modelo Publish-Subscribe utilizando MQTT.

---

# Arquitetura MQTT

Publicador
↓
Broker MQTT (Mosquitto)
↓
Assinantes

O publicador não conhece os consumidores.

Os consumidores não conhecem o publicador.

Toda comunicação ocorre através do Broker.

---

# Componentes

## Broker

Mosquitto MQTT.

Responsável por receber e distribuir mensagens.

## Publicador

Atualmente utilizamos um simulador MQTT.

Futuramente será substituído por uma ESP32 com sensores reais.

## Assinante

Consome os dados publicados nos tópicos MQTT.

---

# Tópicos Utilizados

smartHome/temperature

smartHome/light

---

# Dados Publicados

Temperatura

Luminosidade

---

# Desacoplamento Espacial

O publicador envia mensagens para o Broker sem conhecer os consumidores.

Os consumidores recebem mensagens sem conhecer o publicador.

---

# Integração com Hardware

Foi preparada uma integração utilizando ESP32.

Para a demonstração utilizamos um simulador MQTT publicando exatamente nos mesmos tópicos que serão utilizados pelo hardware.

A ESP32 será responsável por:

* Ler temperatura
* Ler luminosidade
* Publicar dados MQTT

---

# Demonstração

Primeiro executamos a API REST.

Em seguida demonstramos os clientes Python e JavaScript acessando os endpoints.

Depois iniciamos o Broker MQTT.

Por fim executamos o simulador MQTT publicando valores de temperatura e luminosidade em tempo real.

Os dados são recebidos pelo subscriber através dos tópicos MQTT.

---

# Conclusão

O Trabalho 3 demonstrou comunicação cliente-servidor através de API REST.

O Trabalho 4 evoluiu a arquitetura para comunicação indireta utilizando Publish-Subscribe com MQTT.

A utilização do Broker eliminou a necessidade de comunicação direta entre produtores e consumidores, reduzindo o acoplamento e aumentando a flexibilidade do sistema distribuído.
