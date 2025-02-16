// Programa que convierte un numero entero a binario

#include "keyb.h"

int numero;
keyb keyb;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  Serial.println("PROGRAMA QUE CONVIERTE NUMERO ENTERO A BINARIO");

  Serial.print("Introduce numero entero a convertir: "); keyb.readInt(numero); Serial.println(numero);
  
  Serial.print("El numero en binario es: "); Serial.println(numero, BIN);
  Serial.print("");

}

void loop() {
  // put your main code here, to run repeatedly:

}
