/*
Autor: A2N
Web: https://arduinlab.wordpress.com
DESCRIPCIÓN DEL PROGRAMA: Lectura teclado
*/


#include <Keypad.h>

const byte filas = 4;
const byte columnas = 4;

char teclas[filas][columnas] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};

byte filasPins[filas] = { 9, 8, 7, 6 };
byte columnasPins[columnas] = { 5, 4, 3, 2 };

Keypad miteclado = Keypad(makeKeymap(teclas), filasPins, columnasPins, filas, columnas);

void setup() {
  Serial.begin(9600);
}

void loop() {
  char tecla = miteclado.getKey();

  if(tecla){
    Serial.println(tecla);
  }
}
