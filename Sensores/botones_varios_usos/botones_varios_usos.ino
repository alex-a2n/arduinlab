/*

Autor: A2N
Web: https://arduinlab.wordpress.com
DESCRIPCIÓN DEL PROGRAMA: Uso de varios pulsadores

*/

// DECLARACIÓN DE PULSADORES

int boton1 = 2;
int boton2 = 3;
int boton3 = 4;
int boton4 = 5;
int boton5 = 6;
int boton6 = 7;

// Declaración de variables para las funciones
//F2:
bool estadoAccion = false;
bool estadoBotonAnterior = HIGH;
//F4:
/*
int tiempoInicio = 0;
int accionRealizada;
*/
// DECLARACIÓN DE FUNCIONES

// Función para hacer algo mientras el botón está presionado
void F1(int boton){ 
 while(digitalRead(boton) == HIGH){ //acciones a hacer mientras que el botón esté presionado
  Serial.print("Boton");Serial.print(boton);Serial.println("ON");
 }
}

// Función2: Se pulsa y se suelta se activa algo, se repite la acción y se para
void F2(int boton){

  bool estadoBoton = digitalRead(boton);

  if(estadoBoton == LOW && estadoBotonAnterior == HIGH)
  {
    delay(50);
    estadoAccion = !estadoAccion;
    if (estadoAccion){
      Serial.println("Acción ACTIVADA");
    }
    else
    {
      Serial.println("Acción DETENIDA");
    }
  }
  estadoBotonAnterior = estadoBoton; // Guardar el estado actual
}

// Función3: contador de pulsaciones

void F3(int boton){
// Función 3: contador de pulsaciones
  static int contador = 0;  // Variable que mantiene su valor entre llamadas
  static bool estadoBotonAnterior = HIGH;  // Guardar estado anterior del botón

  bool estadoBoton = digitalRead(boton);

  if (estadoBoton == LOW && estadoBotonAnterior == HIGH) {  // Detectar flanco de bajada
   
    Serial.print("Número de pulsaciones: ");
    Serial.println(contador);
    contador++;  // Aumentar contador
    delay(50);  // Pequeño debounce
  }

  estadoBotonAnterior = estadoBoton;  // Actualizar estado anterior
}

void F4(int boton) {
  static bool estadoBotonAnterior = HIGH;  // Estado anterior del botón
  static unsigned long tiempoInicio = 0;  // Guardar el tiempo de inicio de la pulsación
  static bool accionRealizada = false;  // Evitar múltiples activaciones
  
  bool estadoBoton = digitalRead(boton);

  // Detectar cuando el botón ha sido presionado (flanco de bajada)
  if (estadoBoton == LOW && estadoBotonAnterior == HIGH) {  
    delay(50); // Pequeño debounce
    tiempoInicio = millis();
    accionRealizada = false;  // Resetear la variable para poder realizar la acción al soltar
  }

  // Detectar cuando el botón ha sido soltado (flanco de subida)
  if (estadoBoton == HIGH && estadoBotonAnterior == LOW) {  
    delay(50); // Pequeño debounce
    unsigned long duracionPulsacion = millis() - tiempoInicio;

    if (!accionRealizada) {  // Solo realizar la acción una vez
      if (duracionPulsacion <= 1000) {  // Pulsación corta
        Serial.println("Acción A");
      } else {  // Pulsación larga
        Serial.println("Acción B");
      }
      accionRealizada = true;  // Marcar que la acción ya fue realizada
    }
  }

  estadoBotonAnterior = estadoBoton;  // Actualizamos el estado del botón
}

void F5(int boton) { // ACCIÓN AL PRESIONAR (FLANCO DE BAJADA)

  static bool estadoBotonAnterior = HIGH;  // Estado anterior del botón

  bool estadoBoton = digitalRead(boton);  // Leer el estado actual del botón

  // Detectar cuando el botón se presiona (flanco de bajada)
  if (estadoBoton == LOW && estadoBotonAnterior == HIGH) {  
    Serial.println("Flanco de bajada");  // Se presionó el botón
  }

  estadoBotonAnterior = estadoBoton;  // Actualizar el estado anterior para la siguiente iteración
}

void F6(int boton) { // ACCIÓN AL SOLTAR (FLANCO DE SUBIDA)

  static bool estadoBotonAnterior = LOW;  // Estado anterior del botón

  bool estadoBoton = digitalRead(boton);  // Leer el estado actual del botón

  // Detectar cuando el botón se suelta (flanco de subida)
  if (estadoBoton == HIGH && estadoBotonAnterior == LOW) {  
    Serial.println("Flanco de subida");  // Se soltó el botón
  }

  estadoBotonAnterior = estadoBoton;  // Actualizar el estado anterior para la siguiente iteración
}



void setup() {
  // put your setup code here, to run once:
  pinMode(boton1, INPUT);pinMode(boton2, INPUT);pinMode(boton3, INPUT);
  pinMode(boton4, INPUT);pinMode(boton5, INPUT);pinMode(boton6, INPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  F1(boton1);
  F2(boton2);
  F3(boton3);
  F4(boton4);
  F5(boton5);
  F6(boton6);
}
