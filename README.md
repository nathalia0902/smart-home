# 🏠 Smart Home RMI

## Sobre o Projeto

Este projeto foi desenvolvido para a disciplina de Sistemas Distribuídos com o objetivo de implementar comunicação distribuída utilizando Remote Method Invocation (RMI) em C++.

A aplicação simula um sistema de automação residencial onde sensores e dispositivos inteligentes podem ser monitorados e controlados remotamente através de chamadas remotas de métodos.

---

# Trabalho 1 — Comunicação entre Processos

Na primeira etapa do projeto foi implementada a comunicação entre processos utilizando:

- Sockets TCP/IP
- Streams personalizados
- Serialização manual de dados
- Comunicação cliente-servidor
- Comunicação UDP para alertas em tempo real

Os objetos eram convertidos manualmente em bytes utilizando streams personalizados e enviados através da rede.

---

# Trabalho 2 — Remote Method Invocation (RMI)

Na segunda etapa do projeto o sistema foi reestruturado utilizando o modelo Remote Method Invocation (RMI).

Agora o cliente não envia bytes diretamente.  
O cliente invoca métodos remotos como se fossem locais, enquanto o middleware realiza automaticamente:

- empacotamento das mensagens
- serialização dos dados
- envio das requisições
- recebimento das respostas
- execução remota dos métodos

A comunicação segue o modelo requisição-resposta.

---

# Tecnologias Utilizadas

- C++
- Programação Orientada a Objetos (POO)
- Comunicação Cliente-Servidor
- Middleware RMI
- JSON
- Sockets TCP/IP
- Serialização de Dados
- CMake

---

# Conceitos Implementados

## Remote Method Invocation (RMI)

O RMI permite que um cliente invoque métodos em objetos remotos como se fossem métodos locais.

---

## Marshalling

Empacotamento dos dados em JSON para envio pela rede.

---

## Unmarshalling

Reconstrução dos dados recebidos após a comunicação.

---

## Passagem por Valor

Os argumentos e resultados dos métodos remotos são serializados em JSON e enviados pela rede.

---

## Passagem por Referência

Implementada utilizando `RemoteObjectRef`, que identifica o objeto remoto através de:

- host
- porta
- nome do serviço

---

# Arquitetura do Sistema

O sistema foi dividido em módulos:

```txt
Cliente
→ Proxy
→ Requestor
→ Rede
→ Dispatcher
→ Invoker
→ Serviço Remoto
````

---

# Estrutura do Projeto

```txt
smart-home-rmi/
│
├── client/
├── server/
├── middleware/
├── common/
└── CMakeLists.txt
```

---

# Entidades

O sistema possui as seguintes entidades:

* Device
* Sensor
* Lamp
* Room
* SmartHome

## Herança (“é-um”)

* Sensor é um Device
* Lamp é um Device

## Agregação (“tem-um”)

* Room possui Devices
* SmartHome possui Rooms

---

# Serviço Remoto

O sistema implementa um serviço remoto de:

## Monitoramento e Controle de Dispositivos Inteligentes

Incluindo:

* leitura de sensores
* controle de dispositivos
* monitoramento de ambientes
* gerenciamento de dispositivos inteligentes

---

# Métodos Remotos

O sistema implementa os seguintes métodos remotos:

* `turnOn()`
* `turnOff()`
* `getTemperature()`
* `setBrightness()`

---

# Protocolo Requisição-Resposta

A comunicação entre cliente e servidor segue o modelo requisição-resposta.

## Exemplo de Request

```json
{
  "objectReference":"SmartHomeService",
  "methodID":"turnOn",
  "arguments":{
      "deviceId":1
  }
}
```

## Exemplo de Reply

```json
{
  "status":"OK",
  "result":"Device turned ON"
}
```

---

# Componentes do Middleware RMI

## Proxy

Simula um objeto local no cliente e transforma chamadas locais em chamadas remotas.

---

## Requestor

Responsável por enviar requisições ao servidor e receber respostas.

---

## Dispatcher

Recebe requisições vindas da rede e encaminha para o Invoker.

---

## Invoker

Desempacota a requisição, identifica o método remoto e executa o serviço correspondente.

---

# Serialização de Dados

A serialização foi implementada utilizando JSON.

Os dados dos métodos remotos são convertidos em mensagens transmissíveis pela rede.

---

# Como Compilar

```bash
mkdir build
cd build
cmake ..
make
```

---

# Como Executar

## Servidor

```bash
./server
```

## Cliente

```bash
./client
```

---

# Exemplo de Execução

```txt
==== SMART HOME CLIENT ====

Device turned ON
Device turned OFF
Temperature: 25.7 C
Brightness set to: 80
```

---

# Autoras

* Maria Eduarda Almeida Rodrigues
* Nathalia de Oliveira Lima

```
```
