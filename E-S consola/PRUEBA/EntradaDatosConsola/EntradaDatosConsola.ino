#include "keyb.h"

keyb teclado;  // Crear una instancia de la clase keyb

void setup() {
  Serial.begin(9600);  // Iniciar la comunicación serial
  while (!Serial);  // Esperar hasta que la comunicación serial esté lista
  Serial.println("Introduce un valor y presiona Enter:");
}

void loop() {
  Serial.print("Entrada: ");
  String entrada = teclado.read();  // Leer la entrada desde la consola

  // Verificar el tipo de dato
  Serial.print("Tipo de dato: ");
  
  if (esNumeroEntero(entrada)) {
    Serial.println("Integer");
    Serial.print("Valor como entero: ");
    Serial.println(entrada.toInt());
  } else if (esNumeroDecimal(entrada)) {
    Serial.println("Float");
    Serial.print("Valor como float: ");
    Serial.println(entrada.toFloat());
  } else if (esBooleano(entrada)) {
    Serial.println("Boolean");
    Serial.print("Valor como booleano: ");
    Serial.println(teclado.readBool());
  } else {
    Serial.println("Texto");
    Serial.print("Valor como texto: ");
    Serial.println(entrada);
  }

  delay(1000);  // Esperar un segundo antes de la siguiente entrada
}

// Función para verificar si es un número entero
bool esNumeroEntero(String entrada) {
  for (int i = 0; i < entrada.length(); i++) {
    if (!isDigit(entrada[i]) && entrada[i] != '-') {
      return false;
    }
  }
  return true;
}

// Función para verificar si es un número decimal (float)
bool esNumeroDecimal(String entrada) {
  bool puntoEncontrado = false;
  for (int i = 0; i < entrada.length(); i++) {
    if (entrada[i] == '.') {
      if (puntoEncontrado) return false;  // Si ya hay un punto, no es válido
      puntoEncontrado = true;
    } else if (!isDigit(entrada[i]) && entrada[i] != '-') {
      return false;
    }
  }
  return puntoEncontrado;  // Si tiene un punto, es un decimal
}

// Función para verificar si es un valor booleano
bool esBooleano(String entrada) {
  entrada.toLowerCase();
  return (entrada == "true" || entrada == "false" || entrada == "1" || entrada == "0");
}