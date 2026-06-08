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

# 4. Onde está o Serviço Remoto?

O serviço remoto está implementado no servidor da API.

Arquivos principais:

server/Server.cpp

server/SmartHomeApiService.cpp

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

# 5. Por que não utilizamos Socket ou RMI?

O requisito do Trabalho 3 era não implementar sockets diretamente nem utilizar RMI.

Neste projeto utilizamos uma biblioteca HTTP pronta.

Não criamos sockets manualmente.

Não utilizamos RPC.

Não utilizamos RMI.

Toda a comunicação foi realizada através da API REST.

---

# 6. Entidades do Sistema

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

# 7. Relacionamentos

## Agregação

Uma SmartHome possui vários Rooms.

Um Room possui vários Devices.

---

## Herança

Lamp é um Device.

Sensor é um Device.

---

# 8. Arquitetura do Trabalho 3

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

# 9. Linguagens Utilizadas

Servidor:

C++

Cliente 1:

Python

Cliente 2:

JavaScript

Assim atendemos ao requisito de possuir pelo menos duas linguagens diferentes da linguagem utilizada pelo serviço.

---

# 10. Endpoints Disponíveis

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

# 11. Como Demonstramos o Trabalho 3

Um integrante executa o servidor.

Outro integrante executa os clientes.

Assim demonstramos a comunicação cliente-servidor solicitada pelo trabalho.

---

# 12. Trabalho 4 – Comunicação Indireta

Neste trabalho evoluímos a arquitetura.

Escolhemos a opção:

Publish-Subscribe.

---

# 13. O que é Publish-Subscribe?

Publish-Subscribe é um modelo onde produtores e consumidores não se comunicam diretamente.

Existe um intermediário chamado Broker.

O produtor publica mensagens.

O Broker recebe as mensagens.

Os consumidores recebem as mensagens do Broker.

---

# 14. Broker Utilizado

Utilizamos o Mosquitto MQTT.

O Mosquitto é responsável por:

* Receber mensagens.
* Armazenar sessões.
* Distribuir eventos.
* Encaminhar mensagens aos assinantes.

---

# 15. Arquitetura MQTT

Publicador
↓
Broker MQTT (Mosquitto)
↓
Subscriber

---

# 16. O que é MQTT?

MQTT é um protocolo leve muito utilizado em IoT.

Ele trabalha com tópicos.

Exemplos:

smartHome/temperature

smartHome/light

---

# 17. Publicador

O publicador gera eventos de sensores.

Atualmente utilizamos:

simulator/mqtt_sensor_simulator.py

---

# 18. Por que não utilizamos a ESP32 na apresentação?

Durante os testes finais tivemos problemas com a placa ESP32.

Para não comprometer a demonstração, utilizamos um simulador MQTT.

O simulador publica exatamente os mesmos tipos de dados que seriam enviados pela ESP32.

A arquitetura distribuída permanece a mesma.

A única diferença é a origem dos dados.

---

# 19. De Onde Vêm os Valores?

Os valores são gerados pelo simulador MQTT.

Exemplo:

Temperatura: 25.8 °C

Luminosidade: 1398 lux

Esses valores são publicados nos tópicos MQTT e consumidos pelos assinantes.

---

# 20. Como a ESP32 Funcionaria?

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

# 21. Onde Está o Desacoplamento?

O publicador não conhece os consumidores.

Os consumidores não conhecem o publicador.

Ambos conhecem apenas o Broker.

Essa característica é chamada de desacoplamento espacial.

---

# 22. Como Demonstramos o Desacoplamento?

Executamos:

1. Subscriber MQTT.
2. Publicador MQTT.

As mensagens são recebidas normalmente.

Depois encerramos o Subscriber.

O Publicador continua funcionando.

Isso demonstra que ele não depende diretamente dos consumidores.

---

# 23. O que o Broker Resolve?

Sem Broker:

Produtor → Consumidor

Com Broker:

Produtor → Broker → Consumidor

O Broker reduz o acoplamento e facilita a escalabilidade.
