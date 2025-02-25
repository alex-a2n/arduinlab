/*

Autor: A2N
Web: https://arduinlab.wordpress.com
DESCRIPCIÓN DEL PROGRAMA: Lectura de potenciómetro

*/

int pot = A0; //potenciometro conectado a A0
int val;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 val = analogRead(pot);
 Serial.println(val);
 delay(100);
}
