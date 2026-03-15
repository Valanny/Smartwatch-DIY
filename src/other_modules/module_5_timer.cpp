/*
Version: 1.0.0
Autor: Estrada Pulido Salvador
Fecha: 14/03/2026

Descripcion:
El siguiente código, el cual dicta como opera la logica de los timer usados para el codigo principal, se divide en 4 secciones
* Librerias y declaraciones - Aqui se especifican los modulos que se emplearon y ejecutaron a lo largo del codigo
* void timer_init() - Aqui se iinicia el conteo desde la ultima pulsasion de boton
* bool timer_ready() - Aqui se rige la logica de suspension de pantalla
* void menu_ready() - Aqui se rige la logica de entrada al menu principal y el encendido de pantalla tras ser apagada
/* 
MOD: Esta sección se usará para especificar las modificaciones que sufra el código.
*/

// Seccion Primera
#include <Arduino.h>
#include "time_down.h"
unsigned long ultimo_push = 0;
const unsigned long menu = 5000;
const unsigned long timeoutms = 15000;

// Seccion Segunda
void timer_init(){
    ultimo_push = millis();
}

// Seccion Tercera
bool timer_ready(){
    if(millis() - ultimo_push >= timeoutms){
        ultimo_push = millis();
        return true;
    }
    return false;
}

// Seccion Cuarta
bool menu_ready(){
    if(millis() - ultimo_push >= menu){
        return true;
    }
    return false;
}
