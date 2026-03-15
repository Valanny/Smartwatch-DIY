/*
Version: 1.0.0
Autor: Estrada Pulido Salvador
Fecha: 14/03/2026

Descripcion:
El siguiente código, el cual dicta las funciones de la pantalla del smartwatch, se divide en 2 secciones
* Librerias y declaraciones - Aqui se especifican los modulos que se emplearon y ejecutaron a lo largo del codigo
* void {funcion}() {codigo} - Aqui se declaran todas las funciones que se van a emplear, asi como su codigo correspondiente

/* 
MOD: Esta sección se usará para especificar las modificaciones que sufra el código.
*/

// Seccion Primera
#include <Arduino.h>
#include <Wire.h>
#include "indice.h"
#include "botones.h"
#include "potenciometro.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
extern int averagePotValue;
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
bool pantalla = false;

// Seccion Segunda
void displayInit(){
    Serial.begin(115200);
    Wire.setSDA(4); 
    Wire.setSCL(5);
    Wire.begin();
    oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    oled.clearDisplay();
    oled.display();
}

void textobienvenida(){
    oled.clearDisplay();
    oled.setTextSize(1);
    oled.setTextColor(SSD1306_WHITE);
    oled.setCursor(16,20);
    oled.print("-----------------");
    oled.setCursor(14,25);
    oled.print("|Hola, bienvenido|");
    oled.setCursor(16,30);
    oled.print("-----------------");
    oled.display(); 
}
void menu(){
    oled.clearDisplay();
    oled.setTextSize(1);
    oled.setTextColor(SSD1306_WHITE);
    oled.setCursor(0,0);
    oled.print("Ajustes:");
    oled.setCursor(0,10);
    oled.print("* Configuracion");
    oled.setCursor(0,20);
    oled.print("* Salud");
    oled.setCursor(0,30);
    oled.print("* Apagar");
    oled.display(); 
}
void selector(){
    oled.fillRect(0, 10*i, 128, 10, SSD1306_INVERSE);
    oled.display(); 
}
void limpiarPantalla(){
    oled.clearDisplay();
    oled.display();
}
void apagarPantalla(){
    oled.clearDisplay();
    oled.setCursor(25, 25);
    oled.setTextColor(SSD1306_INVERSE);
    oled.print("Apagando...");
    oled.display();
    delay(2000);
    oled.ssd1306_command(SSD1306_DISPLAYOFF); 
}
void encenderPantalla(){
    oled.ssd1306_command(SSD1306_DISPLAYON); 
}
void preguntarApagar(){
    oled.clearDisplay();
    oled.setTextSize(1);
    oled.setTextColor(SSD1306_WHITE);
    oled.setCursor(0,0);
    oled.print("Estas segura?");
    oled.setCursor(0,10);
    oled.print("* Si");
    oled.setCursor(0,20);
    oled.print("* No");
    oled.setCursor(0,30);
    oled.print("Solo suspender");
    oled.display();
}
void hold(){
    static unsigned long tiempo_zzz = 0;
    static bool estado_zzz = false;
    if (!enter() && !up_button() && !down_button()){
        if (millis() - tiempo_zzz >= 500){
            tiempo_zzz = millis();
            estado_zzz = !estado_zzz;
            oled.clearDisplay();
            oled.setTextSize(1);
            oled.setTextColor(SSD1306_WHITE);
            oled.setCursor(0, 0);
            oled.print("|Smartwatch|");
            oled.setCursor(0,10);
            oled.print("|Suspendido|");
            oled.setTextSize(4);
            oled.setCursor(25, 30);
            if (estado_zzz) oled.print("ZzZ");
            else oled.print ("zZz");
            oled.display();
        }
        oled.display();
    }
}
void config(){
    oled.clearDisplay();
    oled.setTextSize(1);
    oled.setTextColor(SSD1306_WHITE);
    oled.setCursor(0,0);
    oled.print("Configuracion");
    oled.setCursor(0,10);
    oled.print("* Opcion 1");
    oled.setCursor(0,20);
    oled.print("* Opcion 2");
    oled.setCursor(0,30);
    oled.print("* Regresar");
    oled.display();
}
void salud(){
    oled.clearDisplay();
    oled.setTextSize(1);
    oled.setTextColor(SSD1306_WHITE);
    oled.setCursor(0,0);
    oled.print("Salud:");
    oled.setCursor(0,10);
    oled.print("* Opcion 1");
    oled.setCursor(0,20);
    oled.print("* Opcion 2");
    oled.setCursor(0,30);
    oled.print("* Regresar");    
    oled.display();
}
void pulso(){
    oled.fillScreen(SSD1306_BLACK);
    oled.setTextSize(1);
    oled.setTextColor(SSD1306_WHITE, SSD1306_BLACK);
    oled.setCursor(0,10);
    oled.print("Pulso Cardiaco:");
    oled.setTextSize(2);
    oled.setCursor(0,30);
    oled.setTextColor(SSD1306_WHITE);
    oled.print(averagePotValue);
    oled.display();
}
void op1(){
    oled.clearDisplay();
    oled.setTextSize(1);
    oled.setTextColor(SSD1306_WHITE);
    oled.setCursor(0,0);
    oled.print("Opcion 1 seleccionada");
    oled.setCursor(0,10);
    oled.print("Presione enter para regresaer");
    oled.display();
}
void op2(){
    oled.clearDisplay();
    oled.setTextSize(1);
    oled.setTextColor(SSD1306_WHITE);
    oled.setCursor(0,0);
    oled.print("Opcion 2 seleccionada");
    oled.setCursor(0,10);
    oled.print("Presione enter para regresaer");
    oled.display();
}
