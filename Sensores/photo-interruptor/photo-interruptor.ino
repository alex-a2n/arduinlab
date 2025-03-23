/*
Autor: A2N
Web: https://arduinlab.wordpress.com
DESCRIPCIÓN DEL PROGRAMA: Lectura foto-interruptor
*/


int Led = 13;
int photointerrupter = 3;  //define el puerto del foto-interruptor
int val;                   //variable digital
void setup() {
  pinMode(Led, OUTPUT);              //define digital variable val
  pinMode(photointerrupter, INPUT);  //definir el módulo de bloqueo de luz como un puerto de entrada
}
void loop() {
  val = digitalRead(photointerrupter);  //leer el valor de la interfaz digital 3 asignado a val
  if (val == HIGH)                      //cuando el sensor de bloqueo de luz tiene señal, el LED parpadea
  {
    digitalWrite(Led, LOW);
  } else {
    digitalWrite(Led, HIGH);
  }
}

