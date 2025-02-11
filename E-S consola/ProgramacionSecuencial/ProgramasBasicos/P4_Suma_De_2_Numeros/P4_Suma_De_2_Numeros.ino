#include "keyb.h"

float num1, num2, resultado;  //Como todas las variables son del mismo tipo se declaran en la misma linea

keyb mikeyb;

void setup() {
  Serial.begin(9600);
}

void loop() {

  Serial.println("***********************************");
  Serial.println("*   PROGRAMA QUE SUMA 2 NUMEROS   *");
  Serial.println("***********************************");
  Serial.println();

  Serial.print("Introduce el numero 1: ");
  num1 = mikeyb.readFloat();
  Serial.println(num1);
  Serial.print("Introduce el numero 2: ");
  num2 = mikeyb.readFloat();
  Serial.println(num2);
  resultado = num1 + num2;
  Serial.print("El resultado es: ");
  Serial.print(resultado);
}