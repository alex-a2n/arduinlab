/*

Autor: A2N
Web: https://arduinlab.wordpress.com
DESCRIPCIÓN DEL PROGRAMA: Control led laser
*/

void setup() {
  pinMode(9, OUTPUT);
}

void loop() {
  for (int i = 0; i <= 255; i += 1) {
    analogWrite(9, i);
    delay(25);
  }
  for (int i = 255; i >= 0; i -= 1) {
    analogWrite(9, i);
    delay(25);
  }
}
