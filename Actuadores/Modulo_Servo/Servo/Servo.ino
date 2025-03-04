/*
Autor: A2N
Web: https://arduinlab.wordpress.com
DESCRIPCIÓN DEL PROGRAMA: Movimiento de servo SG90
*/

#include <Servo.h>

int pinServo = 9;  //Servo conectado en el pin 9
Servo miServo; //Creacción objeto miServo
int valorServo = 0; //Inicialización valor servo

void setup() {
  miServo.attach(pinServo);
}

void loop() {
  //lectura servo
  for(int i = 0; i<181; i++){
    miServo.write(i);
    delay(100);
  }

  for(int i = 180; i>= 0; i--){
    miServo.write(i);
    delay(100);
  }
}
