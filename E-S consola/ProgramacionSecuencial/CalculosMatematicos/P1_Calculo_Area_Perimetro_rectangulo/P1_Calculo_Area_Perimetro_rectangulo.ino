#include "keyb.h"

float area = 0;
float perimetro = 0;
keyb mykeyb;
float lado1 = 0;
float lado2 = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("PROGRAMA QUE CALCULA AREA Y PERIMETRO DE UN RECTANGULO");
  Serial.println();
  Serial.print("Introduce lado 1: "); mykeyb.readFloat(lado1); Serial.println(lado1);
  Serial.print("Introduce lado 2: "); mykeyb.readFloat(lado2); Serial.println(lado2);
  Serial.println();
  area = lado1 * lado2; perimetro = (2*lado1) + (2*lado2);
  Serial.print("El area de rectangulo es: "); Serial.println(area);
  Serial.print("El perimetro del rectangulo es: "); Serial.println(perimetro);
  


}

void loop() {
  // put your main code here, to run repeatedly:

}
