// se asocian los bits a sus pines digitales a modo de lista, reduciendo lineas de codigo
const int pines[4] = {4, 5, 6, 7};
int waitDelay = 500; 
 //cada uno de los 4 pines hace salida digital y se recorren
void setup() {
  for (int i = 0; i < 4; i++) pinMode(pines[i], OUTPUT);
}
// Recorremos todos los valores decimales de 0 a 14 (salto de 2 en 2)
void loop() {
  for (int numero = 0; numero <= 14; numero+=2) {
    for (int bit = 0; bit < 4; bit++) {
      digitalWrite(pines[bit], bitRead(numero, bit));
    }
    delay(waitDelay);
  }
}