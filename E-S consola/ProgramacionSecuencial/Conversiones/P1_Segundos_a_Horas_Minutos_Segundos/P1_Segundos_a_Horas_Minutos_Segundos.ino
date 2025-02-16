//Segundos a horas, minutos y segundos

#include "keyb.h"

int horas, minutos, segundos, segundos_restantes;

keyb mykeyb;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  Serial.println("PROGRAMA QUE CONVIERTE SEGUNDOS EN HORAS, MINUTOS Y SEGUNDOS");
  Serial.println();
//  while (!Serial.available());

  Serial.print("Ingrese segundos: "); mykeyb.readInt(segundos); Serial.println(segundos);

  horas = segundos / 3600;
  minutos = (segundos % 3600) / 60;
  segundos_restantes = segundos % 60;

  Serial.print("Tiempo equivalente: "); Serial.print(horas); Serial.print(" h "); Serial.print(minutos); Serial.print(" min "); Serial.print(segundos_restantes); Serial.println(" s ");


}

void loop() {
  // put your main code here, to run repeatedly:

}
