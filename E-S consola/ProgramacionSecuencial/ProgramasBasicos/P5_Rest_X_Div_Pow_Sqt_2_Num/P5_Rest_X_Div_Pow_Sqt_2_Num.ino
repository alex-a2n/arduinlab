#include "keyb.h"

float num1, num2, resultado1, resultado2, resultado3, resultado4, resultado5, resultado6; //Como todas las variables son del mismo tipo se declaran en la misma linea

keyb mikeyb;

void setup() {
  Serial.begin(9600);

  Serial.println("************************************");
  Serial.println("*   PROGRAMA QUE OPERA 2 NUMEROS   *");
  Serial.println("************************************");
  Serial.println();

  Serial.print("Introduce el numero 1: ");
  num1 = mikeyb.readFloat();
  Serial.println(num1);
  Serial.print("Introduce el numero 2: ");
  num2 = mikeyb.readFloat();
  Serial.println(num2);

  resultado1 = num1 + num2;
  Serial.print("El resultado suma es: ");
  Serial.println(resultado1);

  resultado2 = num1 - num2;
  Serial.print("El resultado resta es: ");
  Serial.println(resultado2);

  resultado3 = num1 / num2;
  Serial.print("El resultado division es: ");
  Serial.println(resultado3);

  resultado4 = num1 * num2;
  Serial.print("El resultado multiplicacion es: ");
  Serial.println(resultado4);

  resultado5 = pow(num1,num2);
  Serial.print("El resultado potencia num1^num2 es: ");
  Serial.println(resultado5);

  resultado6 = sqrt(num1);
  Serial.print("La raiz cuadrada de num1 es: ");
  Serial.println(resultado6);

}

void loop() {


}