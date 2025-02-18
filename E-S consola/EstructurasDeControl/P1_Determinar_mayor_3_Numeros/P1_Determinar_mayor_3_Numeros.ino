// Determinar mayor de 3 numeros ingresados por teclado
#include "keyb.h"

int num1, num2, num3;
keyb mykeyb;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("INTRODUCE 3 NUMEROS:");
  Serial.print("Numero 1: "); mykeyb.readInt(num1); Serial.println(num1);
  Serial.print("Numero 2: "); mykeyb.readInt(num2); Serial.println(num2);
  Serial.print("Numero 3: "); mykeyb.readInt(num3); Serial.println(num3);

  if (num1 > num2 && num1 > num3){
    Serial.println("num1 es el mayor");
  }

  if (num2 > num1 && num2 > num3){
    Serial.println("num2 es el mayor");
  }

  if (num3 > num2 && num3 > num1){
    Serial.println("num3 es el mayor");
  }
  
}
