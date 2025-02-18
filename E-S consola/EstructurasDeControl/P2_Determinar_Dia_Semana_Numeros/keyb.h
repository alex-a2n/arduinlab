#ifndef KEYB_H
#define KEYB_H

class keyb{
  public:
   //Función para leer texto en formato String
   String read(){
    String entrada = ""; //variable para almacenar la entrada
    while (true){ //bucle infinito hasta que se presione "Enter"
      if(Serial.available()>0){ //Si hay datos disponibles, esta linea es imprescindible
        char caracter = Serial.read();
        if(caracter == '\n' || caracter == '\r'){ //Fin de la entrada '\n' es  
          break;
        }
        entrada += caracter; // Añadir el carácter a la cadena
      }
    }
    entrada.trim();
    return entrada;
   }

  //Funciones para leer otro tipo de datos convirtiendo el string al nuevo tipo de dato

  //Leer Bool
  bool readBool(){
     String entrada = read();
        entrada.toLowerCase();
        return (entrada == "1" || entrada == "true");
  }
void readBool(bool &num) { num = readBool();} 

  //Leer boolean
  bool readBoolean(){
    return readBool();
  } 
void readBoolean(bool &num) { num = readBool(); }

  //Leer byte
  byte readByte() {
        int valor = read().toInt();  // Leemos la entrada como entero
        if (valor < 0) valor = 0;    // Asegurarnos que esté en el rango válido
        if (valor > 255) valor = 255;  // Asegurarnos que no sobrepase el rango
        return (byte)valor;  // Convertimos a byte
    }
void readByte(byte &num) { num = readByte(); }

  //Leer float
  float readFloat(){
    return read().toFloat();
  }
void readFloat(float &num) { num = readFloat(); }

  //Leer Int
  int readInt(){
    return read().toInt();
  }
void readInt(int &num) { num = readInt(); }

  //Leer unsignedInt
  unsigned int readUnsignedInt(){
    int valor = read().toInt();
        if (valor < 0) valor = 0;  // No permitir números negativos
        return (unsigned int)valor;
  }
void readUnsignedInt(unsigned int &num) { num = readUnsignedInt(); }

  //Leer char
  char readChar(){
    String entrada = read();
    return (entrada.length() > 0) ? entrada[0] : '\0';  // Retornamos el primer carácter o '\0' si está vacío
  }
void readChar(char &num) { num = readChar(); }

  //Leer double
  double readDouble(){
    return read().toFloat();
  }
void readDouble(double &num) { num = readDouble(); }

  //Leer long
  long readLong() {
        String entrada = read();
        char *endPtr;
        long valor = strtol(entrada.c_str(), &endPtr, 10);
        return (*endPtr == '\0') ? valor : 0;
    }
    void readLong(long &num) { num = readLong(); }

  //Leer unsignedlong
  unsigned long readUnsignedLong() {
        long valor = read().toInt();
        if (valor < 0) valor = 0;  // No permitir números negativos
        return (unsigned long)valor;
    }
void readUnsignedLong(unsigned long &num) { num = readUnsignedLong(); }
};

#endif