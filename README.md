# Contador Binario con Arduino
Este proyecto basico de la mecatrónica consiste en ir representando numeros del sistema decimal al sistema binario mediante 4 LEDS, y en el que cada LED representa un bit. Arduino se encarga de controlar la secuencia de conteo mediante un programa que incrementa el valor automaticamente y actualiza el estado del LED. Cabe mencionar que esto se puede apreciar ya que estos LEDS toman dos unicos valores (ON/OFF, HIGH/LOW) por lo que el sistema binario favorece mucho estas condiciones.

## 2. Materiales utilizados

- 1 Arduino (Uno o similar)
- 5 LEDs (4 para representar los bits + 1 indicador)
- 5 resistencias de 220Ω (una por cada LED, para limitar la corriente)
- Cables de conexión (protoboard jumpers)
- 1 protoboard

## 3. Explicación del circuito

- **LEDs**: cada uno de los 4 LEDs de datos se conectó a un pin digital de salida (4, 5, 6 y 7), con el ánodo (pata larga) hacia el pin y el cátodo (pata corta) hacia la resistencia.
- **Resistencias**: se colocó una resistencia de 220Ω en serie con cada LED, entre el cátodo del LED y GND, para limitar la corriente y evitar que el LED se dañe.
- **Pines digitales**: los pines 4, 5, 6 y 7 se configuraron como `OUTPUT` para controlar los LEDs de datos.
- **GND**: todas las resistencias de los LEDs se conectaron a la tierra (GND) común del Arduino, cerrando el circuito.

## 4. Funcionamiento del contador binario

Con 4 LEDs es posible representar 2⁴ = 16 combinaciones distintas, es decir, los números del 0 al 15. Cada LED corresponde a una posición binaria (bit), con un valor asociado de potencia de 2:

| LED | Valor |
|-----|-------|
| LED 1 | 1 (2⁰) |
| LED 2 | 2 (2¹) |
| LED 3 | 4 (2²) |
| LED 4 | 8 (2³) |

Sumando los valores de los LEDs que están encendidos se obtiene el número decimal representado. Por ejemplo, si LED 4 y LED 2 están encendidos (8 + 2), el número representado es 10, que en binario es `1010`.

## 5. Explicación del código

- **`setup()`**: función que se ejecuta una única vez al iniciar el programa. Se usa para configurar los pines como entrada o salida antes de que comience el ciclo principal.
- **`loop()`**: función que se ejecuta de manera repetida e infinita mientras el Arduino esté encendido. Aquí vive la lógica principal del contador (incrementar el número, actualizar los LEDs).
- **`pinMode()`**: define si un pin va a funcionar como entrada (`INPUT`) o salida (`OUTPUT`). Es necesario configurarlo antes de leer o escribir en ese pin.
- **`digitalWrite()`**: envía una señal digital (HIGH o LOW) a un pin configurado como salida, encendiendo o apagando el LED conectado a él.
- **`digitalRead()`**: lee el estado (HIGH o LOW) de un pin configurado como entrada; se usó para detectar si el pulsador estaba presionado o no.
- **`delay()`**: pausa la ejecución del programa durante una cantidad de milisegundos determinada, usada para que el conteo sea visible y no cambie demasiado rápido.
- **Arreglos**: se usó un arreglo (`pines[]`) para almacenar los números de los pines conectados a cada LED. Esto evita repetir código, ya que se puede recorrer el arreglo con un ciclo en vez de escribir una línea de `digitalWrite()` por cada LED.
- **Ciclos `for`**: se usaron para recorrer los valores del contador (de 0 a 15) y también para recorrer cada uno de los 4 bits de un número, evitando escribir manualmente el código repetido para cada LED o cada valor.
- **Operador `%`**: (si aplica) se usó para determinar si un número es par o impar, ya que `numero % 2 == 0` es verdadero únicamente cuando el número es par.

## 6. Desarrollo de los cinco retos

### Reto 1 — Contador original
- Se solicitaba construir un contador binario básico que recorra los valores del 0 al 15 mostrando su representación en 4 LEDs.
- se implementó el ciclo principal en `loop()`, recorriendo `numero` de 0 a 15 y actualizando cada LED según el bit correspondiente.
- **Parte del código modificada:** `loop()`, usando el arreglo `pines[]` y un ciclo `for` interno para escribir cada bit.
- **Resultado obtenido:** los LEDs muestran correctamente, en secuencia, la representación binaria de cada número del 0 al 15.

### Reto 2 — Contador descendente
- Se solicitaba modificar el contador para que en vez de contar de forma ascendente (0→15), cuente de forma descendente (15→0).
- se invirtieron los valores inicial y final del ciclo `for`, y se cambió el incremento por un decremento.
- **Parte del código modificada:** la línea `for (int numero = 15; numero >= 0; numero--)` en `loop()`.
- **Resultado obtenido:** los LEDs representan la cuenta regresiva desde 1111 (15) hasta 0000 (0).

### Reto 3 — Mostrar solamente números pares
- Se solicitaba modificar el contador para que solo muestre los números pares (0, 2, 4, 6, 8, 10, 12, 14).
   se cambió el incremento del ciclo `for` de `numero++` a `numero += 2`.
- **Parte del código modificada:** la línea `for (int numero = 0; numero <= 14; numero += 2)` en `loop()`.
- **Resultado obtenido:** los LEDs solo representan los valores pares, saltando directamente de un número par al siguiente.

### Reto 5 — LED indicador
- Se solicitaba agregar un quinto LED que permanezca apagado durante el conteo normal y se encienda únicamente cuando el contador llegue a 15 (1111).
   se agregó un pin adicional para el LED indicador y una condición (`if (numero == 15)`) que lo enciende solo en ese caso específico.
- **Parte del código modificada:** se añadió el pin extra en el arreglo `pines[]`, su configuración en `setup()`, y el bloque `if/else` dentro de `loop()` que controla el LED indicador.
- **Resultado obtenido:** el quinto LED permanece apagado durante todo el conteo y se enciende únicamente cuando los 4 LEDs de datos muestran 1111 (valor 15).
