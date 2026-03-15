/*
Version: 1.0.1
Autor: Estrada Pulido Salvador
Fecha: 13/03/2026

Descripcion:
El siguiente código, el cual meramente ejecuta varias funciones en base a un switch case, se compone en 4 secciones:
* Librerias y declaraciones - Aqui se especifican los modulos que se emplearon y ejecutaron a lo largo del codigo
* void setup() - Aqui se inicializan parametros que se utilizaran en el bucle del codigo principal
* enum - Aqui se clasifican los estados para el switch case que dicta el siguiente paso del codigo
* void loop() - Aqui se ejeuctan en bucle las varias funciones previamente llamadas desde sus respectivos modulos

/* 
MOD: Esta sección se usará para especificar las modificaciones que sufra el código.
v1.0.1 
* Se removio documentacion innecesaria
*/

// Seccion Primera
#include <Arduino.h>
#include "display.h"
#include "botones.h"
#include "time_down.h"
#include "indice.h"
#include "potenciometro.h"

// Seccion Segunda
void setup() {
  displayInit();
  timer_init();
  botonesInit();
  medicion();
}

// Seccion Tercera
enum estado {BIENVENIDA, MENU, CONFIG1, CONFIG2, SALUD1, SALUD2, HOLD, 
  CONFIG, SALUD, REGRESAR1, REGRESAR2, PREGUNTAR};

// Seccion Cuarta
void loop() {
  lectura();
  static estado estado_actual = BIENVENIDA;
  static bool dibujado = false; // Se declaran estaticos tanto el estado actual como el dibujado para una inicializacion correcta
  switch (estado_actual) {
    case BIENVENIDA:
    static unsigned long tiempo_presionado = 0; // Se declara la logica para el mantenido de boton por 5 segundos
    if(!dibujado){
      textobienvenida();
      timer_init();
      dibujado = true; // Se declara el dibujado como verdadero para empezar a dibujar el selector
    }
    if(enter()){ // Llamado a la funcion de entrada del usuario. Como se ocupa en el resto del codigo de forma igual, solo se especificara aqui
      if(tiempo_presionado == 0){
        tiempo_presionado = millis(); // Se empieza a contar el tiempo
      }
      if(millis() - tiempo_presionado > 5000){ 
        estado_actual = MENU;
        dibujado = false;
        tiempo_presionado = 0;
        timer_init(); // Al estar presionado por mas de 5 minutos, se permite acceso al menu principal
      }
    }
    else tiempo_presionado = 0;
    if (timer_ready() && !enter()) {
      dibujado = false;
      estado_actual = HOLD;
      tiempo_presionado = 0;
    } // En caso que no se haya presionado el boton en un tiempo determinado, la pantalla entra a un estado de suspension
    break;
    case MENU:
      static bool dibujado_menu = false;
      if(!dibujado_menu){
        menu(); // Llamado a la funcion del muno principal
        selector();
        dibujado_menu = true; // Declaracion del dibujado del menu, se realiza al iniciar cada menu, por lo que solo en esta linea se aclara su funcion
      }
      if (enter()) {
        delay(200);
        dibujado_menu = false; // Se vuelve falso el trazo para evitar que uno se sobreponga y toda la pantalla se quede con el dibujo anterior
        if (i == 1) estado_actual = CONFIG;
        else if (i == 2) estado_actual = SALUD;
        else if (i == 3) estado_actual = PREGUNTAR;
        timer_init(); // Seleccion de caso en base a un indice preestablecido, como ocurre en todos los menus, solo se especificara su funcion en esta linea
      }
      else if (up_button()) {
        up();
        menu();
        selector();
        timer_init(); // Logica del boton de subida. Como dicha logica se ocupa en todo el codigo, solo se describira aqui
      }
      else if (down_button()) {
        down();
        menu();
        selector();
        timer_init(); // Logica del boton de bajada. Como dicha logica se ocupa en todo el codigo, solo se describira aqui
      }
      else if (timer_ready()) {
        estado_actual = HOLD; // Misma logica de suspension de dispositivo
      }
      break;
      case CONFIG:
      if(!dibujado_menu){
        config(); // LLamado a la funcion del menu de configuracion
        selector();
        dibujado_menu = true;
      }
      if (enter()) {
        delay(200);
        dibujado_menu = false;
        if (i == 1) estado_actual = CONFIG1;
        else if (i == 2) estado_actual = CONFIG2;
        else if (i == 3) estado_actual = REGRESAR1; // En caso de haberse equivocado de menu
        timer_init();
      }
      else if (up_button()) {
        up();
        config();
        selector();
        timer_init();
      }
      else if (down_button()) {
        down();
        config();
        selector();
        timer_init();
      }
      else if (timer_ready()) {
        estado_actual = HOLD;
      }
      break;
      case CONFIG1:
      op1(); // Llamado a la funcion que ejecuta la primera opcion
      if (timer_ready()) {
        estado_actual = HOLD;
      }
      if (enter() || up_button() || down_button()) {
        estado_actual = CONFIG;
        encenderPantalla();
        timer_init(); // Tras haber seleccionado la opcion, se espera a que el usuario interactue con cualquiera de los 3 botones para volver al menu en el que se encontraba
      }
      break;
      case CONFIG2:
      op2(); // Llamado a la funcion que ejecuta la segunda opcion
      if (timer_ready()) {
        estado_actual = HOLD;
      }
      if (enter() || up_button() || down_button()) {
        estado_actual = CONFIG;
        encenderPantalla();
        timer_init();
      }
      break;
      case REGRESAR1:
        estado_actual = MENU;
        encenderPantalla();
        timer_init(); // Llamado a la funcion que retorna al menu anterior al previo
      break;
      case SALUD:
      if(!dibujado_menu){
        salud();
        selector();
        dibujado_menu = true;
      }
      if (enter()) {
        delay(200);
        dibujado_menu = false;
        if (i == 1) estado_actual = SALUD1;
        else if (i == 2) estado_actual = SALUD2;
        else if (i == 3) estado_actual = REGRESAR2;
        timer_init();
      }
      else if (up_button()) {
        up();
        salud();
        selector();
        timer_init();
      }
      else if (down_button()) {
        down();
        salud();
        selector();
        timer_init();
      }
      else if (timer_ready()) {
        estado_actual = HOLD;
      }
      break;
      case SALUD1:
      pulso();
      if (timer_ready()) {
        estado_actual = HOLD;
      }
      if (enter() || up_button() || down_button()) {
        estado_actual = SALUD;
        encenderPantalla();
        timer_init();
      }
      break;
      case SALUD2:
      op2();
      if (timer_ready()) {
        estado_actual = HOLD;
      }
      if (enter() || up_button() || down_button()) {
        estado_actual = SALUD;
        encenderPantalla();
        timer_init();
      }
      break;
      case REGRESAR2:
        estado_actual = MENU;
        encenderPantalla();
        timer_init();
      break;
      case PREGUNTAR:
      if(!dibujado_menu){
        preguntarApagar();
        selector();
        dibujado_menu = true; // Pregunta al usuario si en verdad desea apagar el dispositivo
      }
      if (enter()) {
        delay(200);
        dibujado_menu = false;
        if (i == 1) {
          apagarPantalla(); // Llamado a la funcion que apaga la pantalla
          if(enter()){
            if(tiempo_presionado == 0){
              tiempo_presionado = millis();
            }
            if(millis() - tiempo_presionado > 5000){ 
              encenderPantalla();
              estado_actual = BIENVENIDA; // Logica de presionado de 5 segundos para encender el reloj
            }
          }
        }
        else if (i == 2) estado_actual = MENU; // Opcion "No", retorna al meno principal
        else if (i == 3) estado_actual = HOLD; // Opcion "Solo suspender", manda al dispositivo a un estado suspendido
        }
        else if (up_button()) {
        up();
        preguntarApagar();
        selector();
        timer_init();
      }
      else if (down_button()) {
        down();
        preguntarApagar();
        selector();
        timer_init();
      }
      break;
      case HOLD:
      hold();
      if (enter() || up_button() || down_button()) {
        estado_actual = BIENVENIDA;
        encenderPantalla();
        timer_init(); // Llamado a la funcion de dispositivo suspendido, esperando a recibir cualquier entrada externa para volver al inicio
      }
      break;
  }
}
