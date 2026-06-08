# Smart Home API + MQTT

## Trabalho 3 – API REST

## Trabalho 4 – Comunicação Indireta com MQTT

### Integrantes

* Maria Eduarda Almeida Rodrigues
* Nathalia de Oliveira Lima

---

# 1. Introdução

O nosso projeto é uma **Smart Home**, ou seja, uma casa inteligente, onde é possível controlar e monitorar dispositivos como lâmpadas, sensores de temperatura e sensores de luminosidade.

Nesta etapa do projeto, apresentamos a implementação do **Trabalho 3**, no qual foi desenvolvida uma **API REST** para realizar a comunicação cliente-servidor.

A ideia geral do projeto é simular uma casa inteligente distribuída, permitindo que clientes externos consigam consultar informações e executar operações remotamente.

No sistema, temos dispositivos como lâmpadas e sensores, e os clientes podem realizar operações como:

* listar os dispositivos da casa;
* ligar uma lâmpada;
* desligar uma lâmpada;
* alterar o brilho de uma lâmpada;
* consultar temperatura;
* consultar luminosidade.

Nos trabalhos anteriores, a comunicação era mais direta entre cliente e servidor. No Trabalho 3, essa comunicação foi reimplementada utilizando uma API REST, seguindo o modelo de requisição e resposta.

---

# 2. Objetivo do Trabalho 3

O objetivo do Trabalho 3 era reimplementar o serviço remoto utilizando **Web Services ou API**, sem utilizar sockets manualmente e sem utilizar RMI.

Para isso, foi criada uma API REST em **C++**.

A API REST funciona seguindo o modelo de **requisição e resposta**. Um cliente faz uma requisição HTTP para uma rota específica do servidor, o servidor processa essa requisição e retorna uma resposta, normalmente em formato JSON.

No nosso projeto, o servidor foi implementado em C++ utilizando:

* `cpp-httplib`, para criação das rotas HTTP;
* `nlohmann/json`, para manipulação dos dados em JSON.

---

# 3. Conceito de API REST

Uma API REST é uma forma de disponibilizar serviços por meio de rotas HTTP.

Cada rota representa um recurso ou uma operação do sistema.

No nosso projeto, por exemplo, a rota:

```http
GET /api/devices
```

é usada para listar os dispositivos cadastrados na Smart Home.

A rota:

```http
POST /api/devices/1/on
```

é usada para ligar o dispositivo de ID 1.

Já a rota:

```http
PUT /api/lamps/1/brightness
```

é usada para alterar o brilho da lâmpada de ID 1.

O REST utiliza métodos HTTP para indicar a intenção da operação. No nosso projeto, usamos:

* `GET`, para consultar dados;
* `POST`, para executar ações, como ligar ou desligar dispositivos;
* `PUT`, para atualizar informações, como o brilho de uma lâmpada.

---

# 4. Arquitetura do Trabalho 3

A arquitetura do Trabalho 3 segue o modelo **cliente-servidor**.

Temos um servidor implementado em **C++**, responsável por expor a API REST.

Também foram implementados dois clientes em linguagens diferentes da linguagem utilizada no servidor:

* cliente em Python;
* cliente em JavaScript.

Esses clientes fazem requisições HTTP para o servidor e recebem respostas em JSON.

A arquitetura pode ser representada da seguinte forma:

```text
Cliente Python
      |
      | Requisições HTTP
      v
+----------------+
|  API REST C++  |
+----------------+
      ^
      | Requisições HTTP
      |
Cliente JavaScript
```

A API recebe as requisições, executa os métodos do serviço e retorna as respostas para os clientes.

Essa estrutura atende ao requisito do trabalho, pois o servidor foi implementado em C++ e os clientes foram implementados em duas linguagens diferentes.

---

# 5. Entidades do Sistema

O sistema foi modelado com algumas entidades principais.

## 5.1 Device

A classe `Device` representa um dispositivo genérico da casa inteligente.

Seus principais atributos são:

* `id`;
* `name`;
* `status`;
* `type`.

Essa classe serve como base para outros tipos de dispositivos.

---

## 5.2 Lamp

A classe `Lamp` representa uma lâmpada inteligente.

Ela herda da classe `Device`, representando uma relação do tipo **“é-um”**, pois uma lâmpada é um dispositivo.

Além dos atributos herdados de `Device`, a classe `Lamp` possui o atributo:

* `brightness`.

Esse atributo representa o nível de brilho da lâmpada.

---

## 5.3 Sensor

A classe `Sensor` representa um sensor da casa inteligente.

Ela também herda da classe `Device`, caracterizando outra relação do tipo **“é-um”**, pois um sensor também é um dispositivo.

A classe `Sensor` possui atributos específicos como:

* `temperature`;
* `unit`.

---

## 5.4 Room

A classe `Room` representa um cômodo da casa.

Um cômodo possui dispositivos associados, o que caracteriza uma relação do tipo **“tem-um”**.

---

## 5.5 SmartHome

A classe `SmartHome` representa a casa inteligente como um todo.

Ela possui uma lista de cômodos, caracterizando outra relação do tipo **“tem-um”**.

---

# 6. Serviços Remotos Implementados

A API implementa vários serviços remotos relacionados ao controle e monitoramento da Smart Home.

## 6.1 Verificar funcionamento da API

```http
GET /api/health
```

Essa rota serve para verificar se a API está funcionando.

Ela retorna uma resposta JSON informando que o servidor está ativo.

---

## 6.2 Consultar informações da casa

```http
GET /api/home
```

Essa rota retorna informações gerais da Smart Home, como o nome da casa e seus cômodos.

---

## 6.3 Listar dispositivos

```http
GET /api/devices
```

Essa rota retorna todos os dispositivos cadastrados no sistema, incluindo lâmpadas e sensores.

---

## 6.4 Buscar dispositivo por ID

```http
GET /api/devices/{id}
```

Essa rota retorna as informações de um dispositivo específico a partir do seu ID.

---

## 6.5 Ligar dispositivo

```http
POST /api/devices/{id}/on
```

Essa rota liga ou ativa um dispositivo.

Por exemplo:

```http
POST /api/devices/1/on
```

liga o dispositivo de ID 1.

---

## 6.6 Desligar dispositivo

```http
POST /api/devices/{id}/off
```

Essa rota desliga ou desativa um dispositivo.

Por exemplo:

```http
POST /api/devices/1/off
```

desliga o dispositivo de ID 1.

---

## 6.7 Consultar temperatura de um sensor específico

```http
GET /api/sensors/{id}/temperature
```

Essa rota consulta a temperatura de um sensor específico.

Por exemplo:

```http
GET /api/sensors/3/temperature
```

consulta a temperatura do sensor de ID 3.

---

## 6.8 Alterar brilho de uma lâmpada

```http
PUT /api/lamps/{id}/brightness
```

Essa rota altera o brilho de uma lâmpada.

Ela recebe um corpo JSON com o novo valor de brilho.

Exemplo:

```json
{
    "brightness": 85
}
```

O valor do brilho deve estar entre 0 e 100.

---

## 6.9 Consultar temperatura atual

```http
GET /api/sensors/temperature
```

Essa rota retorna a temperatura atual do ambiente.

Ela foi adicionada para preparar a integração com sensores físicos e com a evolução do Trabalho 4.

---

## 6.10 Consultar luminosidade atual

```http
GET /api/sensors/light
```

Essa rota retorna o valor atual de luminosidade.

Ela também foi adicionada para preparar a integração com sensores físicos e com a comunicação indireta utilizando MQTT.

---

# 7. Demonstração do Trabalho 3

Para demonstrar o funcionamento do Trabalho 3, primeiro iniciamos o servidor da API.

Dentro da pasta `build`, executamos:

```bash
./smart_home_api
```

Quando o servidor inicia, ele mostra uma mensagem indicando que a API está rodando em:

```text
http://localhost:8080/api/health
```

Em seguida, podemos abrir no navegador a rota:

```text
http://localhost:8080/api/health
```

Essa rota retorna um JSON confirmando que a API está funcionando.

Também podemos acessar:

```text
http://localhost:8080/api/devices
```

Essa rota mostra todos os dispositivos cadastrados na Smart Home.

Outras rotas que podem ser testadas no navegador são:

```text
http://localhost:8080/api/home
```

```text
http://localhost:8080/api/sensors/temperature
```

```text
http://localhost:8080/api/sensors/light
```

---

# 8. Execução dos Clientes

Além dos testes pelo navegador, também foram implementados dois clientes para consumir a API.

## 8.1 Cliente Python

Para executar o cliente Python, usamos:

```bash
python3 clients/python_client.py
```

Esse cliente realiza várias chamadas para a API, como:

* verificar se a API está funcionando;
* listar dispositivos;
* ligar uma lâmpada;
* alterar o brilho da lâmpada;
* consultar temperatura;
* consultar luminosidade;
* desligar a lâmpada.

---

## 8.2 Cliente JavaScript

Para executar o cliente JavaScript, usamos:

```bash
node clients/js_client.js
```

Esse cliente também consome a API REST e exibe as respostas JSON no terminal.

Com isso, mostramos que o servidor C++ pode ser acessado por clientes em diferentes linguagens de programação.

---

# 9. Como Compilar o Projeto

Na raiz do projeto, execute:

```bash
mkdir build
cd build
cmake ..
make
```

Após a compilação, será gerado o executável:

```bash
smart_home_api
```

---

# 10. Como Executar o Servidor

Dentro da pasta `build`, execute:

```bash
./smart_home_api
```

Se o servidor iniciar corretamente, será exibida uma mensagem semelhante a:

```text
======================================
 Smart Home API iniciada com sucesso
 URL: http://localhost:8080/api/health
======================================
```

---

# 11. Testes Rápidos com curl

Também é possível testar a API pelo terminal usando `curl`.

Verificar a API:

```bash
curl http://localhost:8080/api/health
```

Listar dispositivos:

```bash
curl http://localhost:8080/api/devices
```

Consultar temperatura atual:

```bash
curl http://localhost:8080/api/sensors/temperature
```

Consultar luminosidade atual:

```bash
curl http://localhost:8080/api/sensors/light
```

Ligar dispositivo:

```bash
curl -X POST http://localhost:8080/api/devices/1/on
```

Desligar dispositivo:

```bash
curl -X POST http://localhost:8080/api/devices/1/off
```

Alterar brilho:

```bash
curl -X PUT http://localhost:8080/api/lamps/1/brightness \
-H "Content-Type: application/json" \
-d '{"brightness": 85}'
```
---

# 12. Trabalho 4 – Comunicação Indireta

Neste trabalho evoluímos a arquitetura.

Escolhemos a opção:

Publish-Subscribe.
Com Publish-Subscribe, os sensores apenas publicam dados em tópicos MQTT e o Broker se responsabiliza por distribuir as mensagens aos assinantes. Dessa forma, novos consumidores podem ser adicionados sem alterar os sensores já existentes.

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


# 18. Como a ESP32 Funcionaria?

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

# 19. Como Demonstramos o Desacoplamento?

Executamos:

1. Subscriber MQTT.
2. Publicador MQTT.

As mensagens são recebidas normalmente.

Depois encerramos o Subscriber.

O Publicador continua funcionando.

Isso demonstra que ele não depende diretamente dos consumidores.

---

