/*

Autor: A2N
Web: https://arduinlab.wordpress.com
DESCRIPCIÓN DEL PROGRAMA: Lectura de LDR

*/

int LDR = A0; //potenciometro conectado a A0
int val;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 val = analogRead(LDR);
 Serial.println(val);
 delay(100);
}