#include "keyb.h"

// char diaSemana[7] = {Lunes, Martes, Miercoles, Jueves, Viernes, Sabado, Domingo};
int numero;
keyb mikeyb;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Introduce numero de dia de la semana: "); mikeyb.readInt(numero); Serial.println(numero);
  switch (numero){
    case 1:
      Serial.println("Lunes");
      break;
    case 2:
      Serial.println("Martes");
      break;
    case 3:
      Serial.println("Miercoles");
      break;
    case 4:
      Serial.println("Jueves");
      break;
    case 5:
      Serial.println("Viernes");
      break;
    case 6:
      Serial.println("Sabado");
      break;
    case 7:
      Serial.println("Domingo");
      break;
    default:
      Serial.println("La semana solo tiene 7 dias");

  }

  
}
