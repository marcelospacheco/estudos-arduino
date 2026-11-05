#include <Arduino.h>

// Projeto 03 - Potenciometro + LED com PWM (Arduino Uno)
// Potenciometro: pino do meio no A0, extremos em 5V e GND.
// LED no pino D9 (tem PWM, marcado com ~ na placa) via resistor de 220 ohms.

const uint8_t PINO_POT = A0;
const uint8_t PINO_LED = 9;
const unsigned long INTERVALO_MS = 50;

void setup() {
  pinMode(PINO_LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int leitura = analogRead(PINO_POT);          // 0 a 1023 (ADC de 10 bits)
  int brilho = map(leitura, 0, 1023, 0, 255);  // 10 bits (0-1023) -> 8 bits (0-255)
  analogWrite(PINO_LED, brilho);               // PWM: duty cycle de 0 a 255

  Serial.print("ADC: ");
  Serial.print(leitura);
  Serial.print(" -> PWM: ");
  Serial.print(brilho);
  Serial.print(" (");
  Serial.print(brilho * 100L / 255);
  Serial.println("%)");

  delay(INTERVALO_MS);
}
