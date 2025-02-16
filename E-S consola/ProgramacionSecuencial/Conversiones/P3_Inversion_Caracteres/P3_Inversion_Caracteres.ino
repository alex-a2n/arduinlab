#include "keyb.h"

keyb mykeyb;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("PROGRAMA QUE INVIERTE LOS CARACTERES DE UNA CADENA");

  Serial.print("Introduce una cadena de texto: ");
  String texto = mykeyb.read();  // Leer la entrada del usuario
  Serial.println(texto);
  // Invertir la cadena
  String textoInvertido = "";
  for (int i = texto.length() - 1; i >= 0; i--) {
    textoInvertido += texto[i];
  }

  // Mostrar la cadena invertida
  Serial.print("Cadena invertida: ");
  Serial.println(textoInvertido);
}

void loop() {
  // put your main code here, to run repeatedly:

}
