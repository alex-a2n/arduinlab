/*
Autor: A2N
Web: https://arduinlab.wordpress.com
DESCRIPCIÓN DEL PROGRAMA: Control Servo con potenciómetro
*/
#include <Servo.h>

int pot = A0;   // Potenciómetro conectado al pin A0
int servo = 7;  // Servo conectado al pin D7
Servo miServo;  // Creacción objeto miServo

void setup() {
  pinMode(pot, INPUT);  // Potenciómetro como entrada
  miServo.attach(servo); // inicialización servo conectado al pin D7
}

void loop() {
  // inicialización valores potenciómetro y servo
  int valPot = 0;
  int valServo = 0;

  valPot = analogRead(pot);  // lectura potenciómetro
  valServo = map(valPot, 0, 1023, 0, 180); // conversión valor potenciómetro a grados
  miServo.write(valServo); // movimiento del servo a los grados indicados por el potenciómetro
}
