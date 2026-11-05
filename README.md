# Estudos Gerais: Arduino, Pico e ESP32 no Wokwi

Cada projeto fica na sua própria pasta, com `platformio.ini`, `wokwi.toml` e `diagram.json`.

> **Importante:** abra a pasta do projeto (ex.: `01-blink-uno`) no VS Code, não esta pasta-pai.
> Alternativa: use um workspace multi-raiz (`File → Add Folder to Workspace`).

## Como rodar um projeto

1. Instale as extensões **PlatformIO IDE** e **Wokwi Simulator** no VS Code.
2. Abra a pasta do projeto e compile (`Ctrl+Alt+B`). Isso gera `.pio/build/<env>/firmware.hex`.
3. Abra o `diagram.json` e clique em ▶ (ou `F1` → *Wokwi: Start Simulator*).

## Trilha de estudo

| # | Pasta | Placa | Projeto | Conceitos | Status |
|---|---|---|---|---|---|
| 01 | [01-blink-uno](01-blink-uno/) | Arduino Uno | LED piscando | `pinMode`, `digitalWrite`, `delay`, resistor | Concluído (testado no Wokwi) |
| 02 | [02-botao-led-uno](02-botao-led-uno/) | Arduino Uno | Botão + LED | `digitalRead`, `INPUT_PULLUP`, debounce, `millis()` | Criado, não testado |
| 03 | [03-potenciometro-pwm-uno](03-potenciometro-pwm-uno/) | Arduino Uno | Potenciômetro + LED PWM | `analogRead`, `analogWrite`, ADC, PWM | Criado, não testado |
| 04 | 04-dht22-uno | Arduino Uno | Sensor DHT22 + Serial | bibliotecas, `Serial` | Pendente |
| 05 | 05-lcd-i2c-uno | Arduino Uno | Display LCD I2C | protocolo I2C | Pendente |
| 06 | 06-blink-pico | Raspberry Pi Pico | Blink, botão, ADC | 3,3 V, GPIO, comparação com o Uno | Pendente |
| 07 | 07-wifi-esp32 | ESP32 | Servidor web + LED | Wi-Fi, IoT | Pendente |
| 08 | 08-mqtt-esp32 | ESP32 | Sensor + MQTT/dashboard | projeto integrado | Pendente |

## Site interativo

Abra [site/index.html](site/index.html) no navegador (duplo clique, sem servidor). Ele funciona como página principal do projeto:

- **Início:** visão geral, comparativo entre as placas e a trilha de projetos.
- **Placas** (Arduino Uno, Raspberry Pi Pico, ESP32): explicação de como cada uma funciona, especificações, pinos, pontos de atenção e a configuração de PlatformIO e Wokwi.
- **Projetos:** parâmetros editáveis (pinos, tempos, valores), simulação visual e os arquivos gerados (`main.cpp`, `diagram.json`, ...) prontos para copiar.

Os endereços usam `#/placa/<id>` e `#/projeto/<número>`, então dá para linkar direto para uma página.

## Convenção de nomes

`NN-tema-placa` (ex.: `01-blink-uno`). O número mantém a ordem de estudo e o sufixo identifica a placa.
