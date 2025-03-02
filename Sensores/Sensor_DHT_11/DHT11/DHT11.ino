#include <DHT.h>

// #define DHTTYPE DHT11
// #define DHTPIN 9

DHT dht(9, DHT11);
float humedad;
float temperatura;

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(1000);
  humedad = dht.readHumidity();
  temperatura = dht.readTemperature();
  if(isnan(humedad) || isnan(temperatura)){
    Serial.println("Error");
    return;
  }
  Serial.print("Humedad: "); Serial.print(humedad);Serial.print("%");
  Serial.print("Temperatura: "); Serial.print(temperatura);Serial.println("ºC");
}
