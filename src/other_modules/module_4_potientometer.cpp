/*
Version: 1.0.0
Autor: Estrada Pulido Salvador
Fecha: 14/03/2026

Descripcion:
El siguiente código, el cual dicta como opera el potenciometro (el cual sera reemplazado por un pulsometro en el futuro) funciona, se divide en 3 secciones:
* Librerias y declaraciones - Aqui se especifican los modulos que se emplearon y ejecutaron a lo largo del codigo
* void medicion() - Aqui se realiza la lectura de la señal analogica del potenciometro
* void lectura() - Aqui se realiza la transicion de ADC a digital, y luego se almacena en una variable para futura impresion

/* 
MOD: Esta sección se usará para especificar las modificaciones que sufra el código.
*/

// Seccion Primera
#include "potenciometro.h"
#include <Arduino.h>
const int POT_PIN = 26; 
const int NUM_READINGS = 10;
int readings[NUM_READINGS];
int readIndex = 0;
long total = 0;
int averagePotValue = 0;

// Seccion Segunda
void medicion() {
    analogReadResolution(12); // La Pico también soporta 12 bits
    for (int i = 0; i < NUM_READINGS; i++) {
        readings[i] = 0;
    }
}

// Seccion Tercera
void lectura() {
  total = total - readings[readIndex];
  readings[readIndex] = 4095 - analogRead(POT_PIN);
  total = total + readings[readIndex];
  readIndex = readIndex + 1;
  if (readIndex >= NUM_READINGS){
      readIndex = 0;
  }
  averagePotValue = total / NUM_READINGS;
}
