// Programa que suma los digitos de un numero
#include "keyb.h"

int num = 0, val = 0;

keyb mikeyb;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("PROGRAMA QUE SUMA LOS DIGITOS DE UN NUMERO");
  Serial.println();
  
  Serial.print("Introduce el numero: ");
  int numero = mikeyb.readInt();
  Serial.println(numero);

  int suma = 0;
  int val = abs(numero); // Para que funciones con numeros negativos

  while (val > 0){
    suma = suma + val % 10;
    val = val/10;
  }  

  Serial.print("La suma de los digitos es: "); Serial.println(suma);

  Serial.println();
}

void loop() {
  // put your main code here, to run repeatedly:

}
