#include <Arduino.h>

// Projeto 01 - Blink externo (Arduino Uno)
// LED externo no pino 13 (D13) via resistor de 220 ohms.

const uint8_t PINO_LED = 13;
const unsigned long INTERVALO_MS = 500;

void setup() {
  pinMode(PINO_LED, OUTPUT);   // define o pino como saída
  Serial.begin(9600);
  Serial.println("Blink iniciado!");
}

void loop() {
  digitalWrite(PINO_LED, HIGH);  // 5V no pino -> LED acende
  Serial.println("LED ligado");
  delay(INTERVALO_MS);

  digitalWrite(PINO_LED, LOW);   // 0V no pino -> LED apaga
  Serial.println("LED desligado");
  delay(INTERVALO_MS);
}
