#include <Arduino.h>

// Projeto 02 - Botao + LED (Arduino Uno)
// Botao no pino D2 com INPUT_PULLUP: solto = HIGH, pressionado = LOW.
// LED no pino D8 via resistor de 220 ohms.
// Comportamento: alterna o LED a cada pressao (toggle), com debounce.

const uint8_t PINO_BOTAO = 2;
const uint8_t PINO_LED = 8;
const unsigned long DEBOUNCE_MS = 20;

bool ledLigado = false;
bool leituraAnterior = HIGH;   // ultima leitura bruta do pino
bool estadoEstavel = HIGH;     // estado aceito depois do debounce
unsigned long ultimaMudanca = 0;
unsigned int contagem = 0;

void setup() {
  pinMode(PINO_BOTAO, INPUT_PULLUP);  // resistor de pull-up interno
  pinMode(PINO_LED, OUTPUT);
  Serial.begin(9600);
  Serial.println("Pronto! Aperte o botao.");
}

void loop() {
  bool leitura = digitalRead(PINO_BOTAO);

  // Qualquer mudanca na leitura reinicia a contagem do debounce.
  if (leitura != leituraAnterior) {
    ultimaMudanca = millis();
    leituraAnterior = leitura;
  }

  // So aceita o novo estado se ele ficou estavel por DEBOUNCE_MS.
  if ((millis() - ultimaMudanca) >= DEBOUNCE_MS && leitura != estadoEstavel) {
    estadoEstavel = leitura;

    if (estadoEstavel == LOW) {  // so reage ao aperto, nao a soltura
      ledLigado = !ledLigado;
      digitalWrite(PINO_LED, ledLigado);
      contagem++;
      Serial.print("Pressao #");
      Serial.print(contagem);
      Serial.println(ledLigado ? " -> LED ligado" : " -> LED desligado");
    }
  }
}
