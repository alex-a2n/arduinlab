/*

Autor: A2N
Web: https://arduinlab.wordpress.com
DESCRIPCIÓN DEL PROGRAMA: "blink" del relé

*/

int rele = 3;

void setup() {
  pinMode(rele, INPUT);
}

void loop() {
  // Encender el relé
  digitalWrite(rele, HIGH);
  delay(1000);
  digitalWrite(rele, LOW);
  delay(1000);
}
