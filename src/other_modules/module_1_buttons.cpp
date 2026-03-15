/*
Version: 1.0.0
Autor: Estrada Pulido Salvador
Fecha: 14/03/2026

Descripcion:
El siguiente código, el cual se encarga de manejar el ingreso de señales en base a botones, se divide en 3 partes:
* Librerias y definiciones - Aqui se especifican los modulos que se emplearon y ejecutaron a lo largo del codigo
* void botonesInit() - Aqui se inicializan parametros que se utilizaran en el bucle del codigo principal
* bool {funcion}() {argumento} - Aqui se marca como booleano 3 funciones que poseen de argumento la asosiacion de la lectura de un boton presionado como LOW

/* 
MOD: Esta sección se usará para especificar las modificaciones que sufra el código.
*/

// Seccion Primera
#include <Arduino.h>
#include "botones.h"
#define up 11            // GP10
#define start_select 10  // GP11
#define down 12          // GP12

// Seccion Segunda
void botonesInit() {
  pinMode(up, INPUT_PULLUP);
  pinMode(start_select, INPUT_PULLUP);
  pinMode(down, INPUT_PULLUP);
}

// Seccion Tercera
bool enter() { return digitalRead(start_select) == LOW; }
bool up_button() { return digitalRead(up) == LOW; }
bool down_button() { return digitalRead(down) == LOW; }
