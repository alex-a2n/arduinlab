bool estadoAccion = false;
bool estadoBotonAnterior = HIGH;
static unsigned long tiempoInicio = 0;   // Tiempo cuando se empezó a presionar el botón
static bool accionRealizada = false;    // Para evitar que se repita la acción mientras el botón está presionado

void Funcion1(int boton){
// Función 1: Hace algo solo mientras el botón esté pulsado
  if(digitalRead(boton) == HIGH) { // Leer el estado dentro del while
    Serial.println("ON");
    delay(50);
  }
  else{
    Serial.println("OFF");
  }
}

void Funcion2(int boton){
// Función 2: Se pulsa y suelta se activa algo, se repite la acción se para
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


void Funcion3(int boton){
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


void Funcion4(int boton){
// Función 4: si se hace un pulsación corta se realiza acción A y si la pulsación es larga la acción B
  static bool estadoBotonAnterior = HIGH;  // Estado anterior del botón

  bool estadoBoton = digitalRead(boton);

  // Detectar cuando el botón ha sido presionado (flanco de bajada)
  if (estadoBoton == LOW && estadoBotonAnterior == HIGH) {  
    tiempoInicio = millis();  // Guardamos el tiempo cuando se empieza a presionar el botón
    accionRealizada = false;  // Resetear la variable para poder realizar la acción al soltar
  }

  // Detectar cuando el botón ha sido soltado (flanco de subida)
  if (estadoBoton == HIGH && estadoBotonAnterior == LOW) {  
    unsigned long duracionPulsacion = millis() - tiempoInicio;  // Tiempo que estuvo presionado el botón

    if (!accionRealizada) {  // Solo realizar la acción una vez
      if (duracionPulsacion <= 500) {  // Pulsación corta
        Serial.println("Acción A");
      } else {  // Pulsación larga
        Serial.println("Acción B");
      }
      accionRealizada = true;  // Marcar que la acción ya fue realizada
    }
  }

  estadoBotonAnterior = estadoBoton;  // Actualizamos el estado del botón
}

void Funcion5(int boton) { // ACCIÓN AL PRESIONAR (FLANCO DE BAJADA)

  static bool estadoBotonAnterior = HIGH;  // Estado anterior del botón

  bool estadoBoton = digitalRead(boton);  // Leer el estado actual del botón

  // Detectar cuando el botón se presiona (flanco de bajada)
  if (estadoBoton == LOW && estadoBotonAnterior == HIGH) {  
    Serial.println("Flanco de bajada");  // Se presionó el botón
  }

  estadoBotonAnterior = estadoBoton;  // Actualizar el estado anterior para la siguiente iteración
}

void Funcion6(int boton) { // ACCIÓN AL SOLTAR (FLANCO DE SUBIDA)

  static bool estadoBotonAnterior = LOW;  // Estado anterior del botón

  bool estadoBoton = digitalRead(boton);  // Leer el estado actual del botón

  // Detectar cuando el botón se suelta (flanco de subida)
  if (estadoBoton == HIGH && estadoBotonAnterior == LOW) {  
    Serial.println("Flanco de subida");  // Se soltó el botón
  }

  estadoBotonAnterior = estadoBoton;  // Actualizar el estado anterior para la siguiente iteración
}
