#include "keyb.h"


keyb mykeyb;
float pi = 3.1416;
float radio = 0;
float altura = 0;
float volumen = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("PROGRAMA QUE CALCULA VOLUMEN DE UN CILINDRO");
  Serial.println();
  Serial.print("Introduce el radio de la base: "); mykeyb.readFloat(radio); Serial.println(radio);
  Serial.print("Introduce la altura del cilindro: "); mykeyb.readFloat(altura); Serial.println(altura);
  Serial.println();
  volumen = altura * pi * pow(radio, 2);
  Serial.print("El volumen del cilindro es: "); Serial.println(volumen);
  


}

void loop() {
  // put your main code here, to run repeatedly:

}
