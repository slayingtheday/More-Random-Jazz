#include <Wire.h>
#include "RTClib.h"
#include "clock.h"
#include <LiquidCrystal.h>



void setup (void) {
 lcd.begin(16,2);
 prep();
}

void loop () { 
  printTime();
  lcdPrint();
}
