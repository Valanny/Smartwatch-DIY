/*
Version: 1.0.0
Autor: Estrada Pulido Salvador
Fecha: 14/03/2026

Descripcion:
El siguiente código, el cual dicta la logica del indice de los menus, contiene 3 secciones:
* Librerias y declaraciones - Aqui se especifican los modulos que se emplearon y ejecutaron a lo largo del codigo
* void up() - Aqui se indica como funciona el boton de subida
* void down() - Aqui se indica como funciona el boton de bajada
/* 
MOD: Esta sección se usará para especificar las modificaciones que sufra el código.
*/

// Seccion Primera
#include <Arduino.h>
#include "indice.h"
int i = 0;
const int numOpciones = 4;
unsigned long tiempo_presionado = 0;
bool presionado = false;
bool menu_activo = false;

// Seccion Segunda
void up(){
    i++;
    if (i >= numOpciones) {
        i = 1;
    }
}

// Seccion Tercera
void down(){
    i--;
    if (i <= 0) {
        i = numOpciones - 1;
    }
}
