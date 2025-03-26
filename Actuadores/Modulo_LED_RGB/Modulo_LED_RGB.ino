/*
Autor: A2N
Web: https://arduinlab.wordpress.com
DESCRIPCIÓN DEL PROGRAMA: Control led RGB con 2 potenciómetros
*/

int pot1 = A0;
int pot2 = A1;
int rojo = 11;
int verde = 12;
int azul = 13;
int val, val2, val3;

void setup() {
  pinMode(pot1, INPUT);
  pinMode(pot2, INPUT);
  pinMode(rojo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);
}

void loop() {
  //Control led Rojo automático
  for (val = 0; val < 255; val++) {
    analogWrite(rojo, val);
    delay(10);
  }
  for (val = 255; val <= 0; val--) {
      analogWrite(rojo, val);
      delay(10);
    }
  //Control led verde con potenciómetro 1
  val2 = analogRead(pot1);
  val2 = map(val2, 0, 1023, 0, 255);
  analogWrite(verde, val2);
  //Control led azul con potenciómetro 2
  val3 = analogRead(pot2);
  val3 = map(val3, 0, 1023, 0, 255);
  analogWrite(azul, val3);
}
