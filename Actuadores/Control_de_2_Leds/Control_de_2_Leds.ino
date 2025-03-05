/*
Autor: A2N
Web: https://arduinlab.wordpress.com
DESCRIPCIÓN DEL PROGRAMA: Control de 2 leds
*/

int pinLed = 2, pinLed2 = 9;

void setup() {
  pinMode(pinLed, OUTPUT);
  pinMode(pinLed2, OUTPUT);
}

void loop() {
  // Control de encendido y apagado
  digitalWrite(pinLed, HIGH);
  delay(1000);
  digitalWrite(pinLed, LOW);
  delay(50);

  // Encendido progresivo con PWM
  for (int i = 0; i <= 255; i++) {
    analogWrite(pinLed2, i); // Usamos analogWrite para PWM
    delay(5); // Pequeño retraso para suavizar el efecto
  }

  // Apagado progresivo con PWM
  for (int i = 255; i >= 0; i--) {
    analogWrite(pinLed2, i);
    delay(5);
  }
}
