# 🏠 Smart Home

## Sobre o Projeto

Este projeto está em desenvolvimento para a disciplina de Sistemas Distribuídos com o objetivo de implementar comunicação entre processos utilizando Sockets e Streams.
A aplicação simula um sistema de automação residencial onde sensores e dispositivos trocam informações através de streams personalizados.

---

## Tecnologias Utilizadas

* C++
* Programação Orientada a Objetos (POO)
* Sockets TCP/IP
* Streams (InputStream e OutputStream adaptados)
* ESP32 (para integração futura com hardware)

---

## Serviço Remoto

O sistema implementa um serviço de:

Monitoramento e Controle de Dispositivos Inteligentes, incluindo:

* Leitura de sensores (temperatura, presença, luminosidade)
* Controle de dispositivos (lâmpadas, ar-condicionado, etc.)

---

## Estrutura do Projeto

### Classes POJO (Dados)

As classes POJO representam os dados do sistema:

* `Sensor`
* `Ambiente`
* `Leitura`

Essas classes armazenam apenas atributos, sem lógica de negócio.

---

### Classes de Modelo

Responsáveis pela lógica do sistema:

* `SensorService`
* `MonitoramentoService`

---

## Comunicação com Streams

### SensorOutputStream

Classe responsável por enviar dados de sensores através de um stream.

#### Funcionalidades:

* Envio de um array de objetos `Sensor`
* Serialização manual dos dados
* Envio do tamanho dos dados + atributos

#### Testes realizados:

* Saída padrão (`cout`)
* Arquivo (`FileOutputStream`)
* Comunicação TCP (cliente)

---

### SensorInputStream

Classe responsável por ler dados enviados via stream.

#### Funcionalidades:

* Desserialização dos dados recebidos
* Reconstrução dos objetos `Sensor`
* Impressão dos dados

#### Testes realizados:

* Entrada padrão (`cin`)
* Arquivo (`FileInputStream`)
* Comunicação TCP (servidor)

---

## Como Executar

### 1. Compilar o projeto

```bash
g++ src/main.cpp -o smart_home
```

### 2. Executar

```bash
./smart_home
```

---

## Autores

* Maria Eduarda Almeida Rodrigues
* Nathalia de Oliveira Lima

---
