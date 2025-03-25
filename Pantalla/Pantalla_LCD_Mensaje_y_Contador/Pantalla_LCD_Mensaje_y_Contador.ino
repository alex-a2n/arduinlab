/*

Autor: A2N
Web: https://arduinlab.wordpress.com
DESCRIPCIÓN DEL PROGRAMA: Pantalla LCD 1602, muestra mensaje fijo en movimiento y un contador

*/

/*

Conexiones Pantalla a Arduino:

- VSS -> Resistencia/potenciómetro y de este a GND
- VDD -> +5Vcc
- V0 -> al otro terminal de la resistencia/potenciómetro y de este a GND
- RS -> D7
- R/W -> a la resistencia/potenciómetro y conexión directa a GND
- E -> D8
- DB0 - DB3 sin conexión
- DB4 -> D9
- DB5 -> D10
- DB6 -> D11
- DB7 -> D12
- A -> +5Vcc
- K -> GND

*/

#include <LiquidCrystal.h>

// Asignación pines pantalla a los pines del microcontrolador
const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Mensaje a mostrar en la pantalla con movimiento
String mensaje = "Arduinlabs, pantalla LCD "; 
int desplazamiento = 0;

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  // Mostrar la parte desplazada del mensaje en la primera línea
  lcd.setCursor(0, 0);
  // Toma una parte del mensaje empezando desde desplazamiento, que es 0, el 1º carácter del string hasta el caracter 16 que es lo que ocupa la pantalla
  lcd.print(mensaje.substring(desplazamiento, desplazamiento + 16)); 

  // Mostrar el contador en la segunda línea (sin moverlo)
  lcd.setCursor(0, 1);
  lcd.print("Tiempo: ");  
  lcd.print(millis() / 1000);
  lcd.print("s   "); // Espacios extra para limpiar

  // Aumenta el desplazamiento del mensaje de 1 en 1 hasta que llega al final de la pantalla
  desplazamiento++;
  if (desplazamiento > mensaje.length() - 16) {
    desplazamiento = 0; // Reinicia el desplazamiento
  }

  delay(500); // Velocidad del desplazamiento
}
