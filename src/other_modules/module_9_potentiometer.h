/*
Version: 1.0.0
Autor: Estrada Pulido Salvador
Fecha: 14/03/2026

Descripcion:
El siguiente código, el cual meramente guarda las funciones como libreria, se compone de 3 secciones:
* Definiciones - Se define el nombre de la libreria y comienza el llamado
* void {funcion}() y extern - Se llama a la funcion y variables y se mantienen en espera
* #endif - Se detiene el llamado

/* 
MOD: Esta sección se usará para especificar las modificaciones que sufra el código.
*/

// Seccion Primera
#ifndef POTENCIOMETRO_H
#define POTENCIOMETRO_H

// Seccion Segunda
extern const int POT_PIN;
extern int averagePotValue;
void medicion();
void lectura();

// Seccion Tercera
#endif
