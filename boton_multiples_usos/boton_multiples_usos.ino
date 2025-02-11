#include "boton.h"

const int boton = 7;

void setup() {
  pinMode(boton, INPUT);
  Serial.begin(9600);
}

void loop() {
 
 // FuncionX(boton); //siendo x un número entre 1 y 6
 
 Funcion6(boton);

}
