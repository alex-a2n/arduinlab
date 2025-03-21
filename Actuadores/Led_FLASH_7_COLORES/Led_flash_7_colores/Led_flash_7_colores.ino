/*

Autor: A2N
Web: https://arduinlab.wordpress.com
DESCRIPCIÓN DEL PROGRAMA: Control led flash 7 colores

*/

int LedPin = 13;

void setup() {
  pinMode(LedPin, OUTPUT);
}

void loop() {
  digitalWrite(LedPin, HIGH);
  delay(4000);
  digitalWrite(LedPin, LOW);
  delay(500);
}
