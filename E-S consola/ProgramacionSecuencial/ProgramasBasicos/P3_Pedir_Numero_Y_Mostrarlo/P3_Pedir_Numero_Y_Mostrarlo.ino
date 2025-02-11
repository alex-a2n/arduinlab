/*

PROGRAMA QUE PIDE NUMERO Y LO MUESTRA

*/

#include "keyb.h"

keyb teclado; //Crear objeto teclado
float numero;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("INTRODUCE UN NUMERO: \n");
  
  numero = teclado.readFloat();

  Serial.print("El numero introducido es:"); Serial.println(numero);
  
}
