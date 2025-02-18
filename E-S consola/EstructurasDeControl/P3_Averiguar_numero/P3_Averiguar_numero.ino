// Averigurar numero 33
#include "keyb.h"

int num;
keyb mykeyb;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("INTRODUCE UN NUMERO HASTA AVERIGUARLO");
  etiqueta:
  mykeyb.readInt(num); Serial.println(num);
  while (num != 33){

   
    if(num < 33){
      Serial.println("El numero que buscas es mayor");
      goto etiqueta;
    }
    if(num > 33){
      Serial.println("El numero que buscas es menor");
      goto etiqueta;
    }
  }
  if (num = 33){
    Serial.print("El numero que buscabas es el 33");
   
  }
  
}
