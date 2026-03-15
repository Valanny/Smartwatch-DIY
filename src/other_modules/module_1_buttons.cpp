#include <Arduino.h>
#include "botones.h"

// Adaptación para Raspberry Pi Pico
#define up 11            // GP10
#define start_select 10  // GP11
#define down 12          // GP12

void botonesInit() {
  pinMode(up, INPUT_PULLUP);
  pinMode(start_select, INPUT_PULLUP);
  pinMode(down, INPUT_PULLUP);
}

bool enter() { return digitalRead(start_select) == LOW; }
bool up_button() { return digitalRead(up) == LOW; }
bool down_button() { return digitalRead(down) == LOW; }
