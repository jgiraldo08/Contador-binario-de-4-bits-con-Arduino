// se asocian los bits a sus pines digitales a modo de lista, reduciendo lineas de codigo
const int pines[5] = {4, 5, 6, 7, 8};  // 4 pines de datos + 1 pin indicador (LED5)
int waitDelay = 2000;

// cada uno de los 5 pines hace salida digital y se recorren
void setup() {
  for (int i = 0; i < 5; i++) pinMode(pines[i], OUTPUT);
}

// Recorremos todos los valores decimales de 0 a 15
void loop() {
  for (int numero = 0; numero <= 15; numero++) {
    // Escribimos los 4 bits en sus respectivos pines
    for (int bit = 0; bit < 4; bit++) {
      digitalWrite(pines[bit], bitRead(numero, bit));
    }

    // LED indicador (LED5): se enciende solo cuando numero == 15 (1111)
    if (numero == 15) {
      digitalWrite(pines[4], HIGH);
    } else {
      digitalWrite(pines[4], LOW);
    }

    delay(waitDelay);
  }
}