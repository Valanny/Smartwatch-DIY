# Smartwatch DIY - Development of hardware and software of a DIY Smartwatch 

## Descripción

Este proyecto consiste en el diseño y desarrollo de un dispositivo tipo Smartwatch wearable con fines puramente educativos. Esta basado en el microcontrolador RP2040 y programado en su totalidad en C++. El reloj integra capacidades de monitoreo de salud mediante el sensor de oximetria y frecuecia cardiaca MAX30100, gestion de energia para baterias Li-Po y una interfaz para el usuario mostrada en un display OLED.

El desarrollo abarca desde el diseño de hardware (Esquematico y PCB) en Autodesk Fusion 360, la validacion de algunos bloques en Proteus/LTspice, hasta la implementacion del firmware usando como editor de codigo VS Code, buscando optimizar el codigo y las funciones dentro del reloj para mejorar el consumo energetico.

---

# Objetivos

## General

Desarrollar un sistema embebido simple del tipo "smartwatch" funcional que integre sensores e ICs para manejar una interfaz visual aplicando multiples areas de la ingenieria en hardware y software.

## Especificos

* **Diseño de Hardware:** Diseñar una PCB compacta y funcional para un wearable basado en RP2040, asegurando la integridad de la señal para los protocolos I2C.
* **Optimizacion:** Del lado del Hardware, implementar multiples formas de forzar al sistema a consumir la menor cantidad de energia para optimizar el tiempo de vida de la bateria Li-Po. Del lado del Software, optimizar el codigo hasta lograr tiempos de carga minimos y evitar lag o delays no deseados en la interface.
* **I2C:** varios de los modulos implementados en el proyecto usan el protocolo I2C para la comunicacion entre los datos, por lo que aprenderlo, entenderlo y aplicarlo es fundamental para poder, por ejemplo, tener la hora precisa con el DS3231MZ o poder tomar el pulso con el MAX30100

---

* Saldaña Ramirez Anna Valentina - Hardware designer, technician, co-programmer
* Estrada Pulido Salvador - Programmer, co-technician
