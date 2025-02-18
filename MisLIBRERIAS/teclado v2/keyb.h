#ifndef KEYB_H
#define KEYB_H

class keyb {
public:
  //Función para leer texto en formato String
  String read() {
        String entrada = "";  // Variable para almacenar la entrada
        
        while (true) {
            if (Serial.available() > 0) { // Si hay datos disponibles en el buffer serial
                char caracter = Serial.read(); // Leer carácter
                
                if (caracter == '\n' || caracter == '\r') { // Si se presiona "Enter"
                    Serial.println(); // Hacer un salto de línea
                    break;
                }

                if (caracter == 8 || caracter == 127) { // Manejo del retroceso (Backspace)
                    if (entrada.length() > 0) {
                        entrada.remove(entrada.length() - 1); // Eliminar último carácter
                        Serial.print("\b \b"); // Borrar visualmente en la consola
                    }
                } else {
                    entrada += caracter; // Agregar el carácter a la cadena
                    Serial.print(caracter); // Mostrar el carácter en la consola en tiempo real
                }
            }
        }
        
        entrada.trim(); 
        return entrada;
  }

  //Funciones para leer otro tipo de datos convirtiendo el string al nuevo tipo de dato

  String readMultiline() {
        String paragraph = "";  // Variable para almacenar el párrafo completo
        String line;  // Variable para cada línea individual
        
        // Leer hasta que el usuario ingrese una línea vacía
        while (true) {
            line = read(); // Leer cada línea

            if (line.length() == 0) { // Si la línea está vacía, termina el párrafo
                break;
            }

            paragraph += line + "\r\n";  // Agregar la línea al párrafo con un salto de línea
        }
        return paragraph;
    }


  //Leer Bool
  bool readBool() {
    String entrada = read();
    entrada.toLowerCase();
    return (entrada == "1" || entrada == "true");
  }
  void readBool(bool &num) {
    num = readBool();
  }

  //Leer boolean
  bool readBoolean() {
    return readBool();
  }
  void readBoolean(bool &num) {
    num = readBool();
  }

  //Leer byte
  byte readByte() {
    int valor = read().toInt();    // Leemos la entrada como entero
    if (valor < 0) valor = 0;      // Asegurarnos que esté en el rango válido
    if (valor > 255) valor = 255;  // Asegurarnos que no sobrepase el rango
    return (byte)valor;            // Convertimos a byte
  }
  void readByte(byte &num) {
    num = readByte();
  }

  //Leer float
  float readFloat() {
    return read().toFloat();
  }
  void readFloat(float &num) {
    num = readFloat();
  }

  //Leer Int
  int readInt() {
    return read().toInt();
  }
  void readInt(int &num) {
    num = readInt();
  }

  //Leer unsignedInt
  unsigned int readUnsignedInt() {
    int valor = read().toInt();
    if (valor < 0) valor = 0;  // No permitir números negativos
    return (unsigned int)valor;
  }
  void readUnsignedInt(unsigned int &num) {
    num = readUnsignedInt();
  }

  //Leer char
  char readChar() {
    String entrada = read();
    return (entrada.length() > 0) ? entrada[0] : '\0';  // Retornamos el primer carácter o '\0' si está vacío
  }
  void readChar(char &num) {
    num = readChar();
  }

  //Leer double
  double readDouble() {
    return read().toFloat();
  }
  void readDouble(double &num) {
    num = readDouble();
  }

  //Leer long
  long readLong() {
    String entrada = read();
    char *endPtr;
    long valor = strtol(entrada.c_str(), &endPtr, 10);
    return (*endPtr == '\0') ? valor : 0;
  }
  void readLong(long &num) {
    num = readLong();
  }

  //Leer unsignedlong
  unsigned long readUnsignedLong() {
    long valor = read().toInt();
    if (valor < 0) valor = 0;  // No permitir números negativos
    return (unsigned long)valor;
  }
  void readUnsignedLong(unsigned long &num) {
    num = readUnsignedLong();
  }
};

#endif