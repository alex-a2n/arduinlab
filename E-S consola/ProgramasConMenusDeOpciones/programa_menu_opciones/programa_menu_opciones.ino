// Programa de menú de opciones
#include "keyb.h"

keyb mykeyb;
int opcion;

void setup() {
  Serial.begin(9600);
  Serial.println("=== MENU DE OPCIONES ===");
  Serial.println("1. Saludar");
  Serial.println("2. Mostrar un número aleatorio");
  Serial.println("3. Mostrar el doble de un número");
  Serial.println("4. Salir");
  Serial.println("========================");
}

void loop() {
  Serial.print("\nElige una opción (1-4): ");
  mykeyb.readInt(opcion);  // Leer opción del usuario
  Serial.println(opcion);  // Mostrar la opción elegida

  switch (opcion) {
    case 1:
      Serial.println("¡Hola! Espero que tengas un buen día.");
      break;
    case 2:
      Serial.print("Número aleatorio: ");
      Serial.println(random(1, 101));  // Número entre 1 y 100
      break;
    case 3:
      int numero;
      Serial.print("Introduce un número: ");
      mykeyb.readInt(numero);
      Serial.println(numero);
      Serial.print("El doble es: ");
      Serial.println(numero * 2);
      break;
    case 4:
      Serial.println("Saliendo del programa...");
      while (true);  // Bucle infinito para detener la ejecución
      break;
    default:
      Serial.println("Opción no válida. Inténtalo de nuevo.");
      break;
  }
}
