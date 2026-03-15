/*
Version: 1.0.0
Autor: Estrada Pulido Salvador
Fecha: 14/03/2026

Descripcion:
El siguiente código, el cual meramente guarda las funciones como libreria, se compone de 3 secciones:
* Definiciones - Se define el nombre de la libreria y comienza el llamado
* void {funcion}() - Se llama a la funcion y se mantiene en espera
* #endif - Se detiene el llamado

/* 
MOD: Esta sección se usará para especificar las modificaciones que sufra el código.
*/

#ifndef DISPLAY_H
#define DISPLAY_H

void displayInit();
void textobienvenida();
void menu();
void selector();
void config();
void salud();
void pulso();
void op1();
void op2();
void limpiarPantalla();
void apagarPantalla();
void encenderPantalla();
void preguntarApagar();
void hold();
extern bool pantalla;

#endif
