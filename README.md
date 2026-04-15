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

## Comunicação TCP (Cliente-Servidor)

O sistema implementa comunicação entre processos utilizando o modelo cliente-servidor com sockets TCP, com foco no envio estruturado de dados dos sensores.

### Funcionamento:

* O cliente coleta dados dos sensores e realiza a **serialização manual** dos objetos `Sensor`
* Os dados são enviados como sequência de bytes através do socket TCP
* O servidor recebe esses bytes diretamente do socket
* Os dados são **desserializados**, reconstruindo os objetos `Sensor`
* Os dados reconstruídos são processados pelo sistema de monitoramento

---

### Integração com Streams

A serialização segue o mesmo padrão definido nos streams personalizados:

* O formato de envio implementado em `SensorOutputStream` foi reutilizado na comunicação TCP
* O processo de leitura segue a mesma lógica de `SensorInputStream`

Essa abordagem garante consistência entre:

* Escrita em arquivos
* Comunicação via rede
* Estrutura dos dados transmitidos

---

### Fluxo da comunicação:

1. Cliente cria objetos `Sensor`
2. Cliente serializa os dados (id, tipo, valor, quantidade)
3. Cliente envia os bytes via socket TCP
4. Servidor recebe os dados via `read()`
5. Servidor desserializa os dados reconstruindo os objetos
6. Servidor processa os sensores (ex: geração de alertas)

---

### Tecnologias utilizadas:

* Sockets TCP (`socket`, `connect`, `accept`, `read`, `write`)
* Serialização manual de dados
* Reutilização do padrão de streams personalizados

---

## Comunicação UDP (Alertas em Tempo Real)

Além do TCP, o sistema utiliza **UDP** para envio de mensagens rápidas, simulando notificações em um ambiente Smart Home.

### Funcionamento:

* Um servidor UDP envia mensagens (alertas)
* Um ou mais clientes UDP recebem essas mensagens
* Comunicação sem necessidade de conexão prévia

### Exemplos de alertas:

* "Temperatura alta!"
* "Ambiente escuro!"
* "Movimento detectado!"

### Características do UDP:

* Comunicação rápida e leve
* Não garante entrega dos dados
* Ideal para notificações em tempo real

---

## Serialização de Dados

Para permitir a comunicação entre processos, os dados são convertidos para um formato transmissível.

### Serialização:

* Conversão de objetos em sequência de bytes
* Implementada manualmente no `SensorOutputStream`

### Desserialização:

* Reconstrução dos objetos a partir dos bytes recebidos
* Implementada no `SensorInputStream`

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
