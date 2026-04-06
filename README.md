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
* `Dispositivo`
* `Ambiente`

Essas classes armazenam apenas atributos, sem lógica de negócio.

---

### Classes de Modelo

Responsáveis pela lógica do sistema:

* `SensorService`
* `DispositivoService`

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

## Comunicação TCP

O projeto implementa comunicação cliente-servidor:

* Cliente envia dados dos sensores
* Servidor recebe e interpreta os dados

---

## Como Executar

### 1. Compilar o projeto

```bash
g++ main.cpp -o smart_home
```

### 2. Executar

```bash
./smart_home
```

---

## Exemplos de Teste

* Envio de dados para o terminal
* Escrita e leitura em arquivos binários
* Comunicação entre cliente e servidor via socket

---

## Integração com ESP32

O sistema pode ser expandido para rodar na ESP32 utilizando:

* WiFi (WiFiClient / WiFiServer)
* Leitura de sensores reais
* Controle de dispositivos físicos

---

## Objetivo Acadêmico

Este projeto atende aos requisitos do trabalho:

✔ Definição de serviço remoto
✔ Criação de classes POJO
✔ Implementação de OutputStream customizado
✔ Implementação de InputStream customizado
✔ Testes com:

* Console
* Arquivo
* TCP

---

## Autores

* Maria Eduarda Almeida Rodrigues
* Nathalia de Oliveira Lima

---

## Observações

Este projeto tem fins acadêmicos e pode ser expandido para aplicações reais de IoT e automação residencial.

---

## Melhorias Futuras

* Integração completa com ESP32
* Interface web para monitoramento
* Uso de JSON para serialização
* Dashboard com análise de dados

---
