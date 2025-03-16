/*

Autor: A2N
Web: https://arduinlab.wordpress.com
DESCRIPCIÓN DEL PROGRAMA: Lectura interruptores de choque, inclinación y toque

*/

int choque = 2, inclinacion = 3, toque = 4;

void setup() {
  Serial.begin(9600);
  pinMode(choque, INPUT);
  pinMode(inclinacion, INPUT);
  pinMode(toque, INPUT);
}

void loop() {

  bool valChoque = digitalRead(choque);
  bool valInclinacion = digitalRead(inclinacion);
  bool valToque = digitalRead(toque);

  Serial.print("sensor choque: "); Serial.print(valChoque);Serial.print('\n');
  Serial.print("sensor inclinacion: "); Serial.print(valInclinacion);Serial.print('\n');
  Serial.print("sensor toque: "); Serial.print(valToque);Serial.print('\n');

  delay(1000);

}
