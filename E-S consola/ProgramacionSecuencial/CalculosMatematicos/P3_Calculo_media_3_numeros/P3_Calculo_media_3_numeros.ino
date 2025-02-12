// Programa que calcula la media de 3 numeros
#include "keyb.h"

float num1, num2, num3, resultado;

keyb mikeyb;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("PROGRAMA QUE CALCULA LA MDEDIA DE 3 NUMEROS");
  Serial.println();
  Serial.print("Introduce el numero 1: "); mikeyb.readFloat(num1);Serial.println(num1);
  Serial.print("Introduce el numero 2: "); mikeyb.readFloat(num2);Serial.println(num2);
  Serial.print("Introduce el numero 3: "); mikeyb.readFloat(num3);Serial.println(num3);

  resultado = (num1+num2+num3)/3;

  Serial.print("El resultado es: "); Serial.println(resultado);


}

void loop() {
  // put your main code here, to run repeatedly:

}
