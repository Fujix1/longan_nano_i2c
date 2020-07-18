/*
 * Blink
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */

#include <Arduino.h>
#include "Wire.h"

const uint8_t MPC4018_ADDRESS = 0x2F;

void setup() {
 
  pinMode(LED_RED, OUTPUT); // 赤 LED
  pinMode(LED_BLUE, OUTPUT); // 青 LED
  pinMode(LED_GREEN, OUTPUT); // 緑 LED

  Wire.begin();

}

int cnt = 12; // 初期抵抗 1kΩ

void loop() {

  digitalWrite(LED_RED, HIGH);
  digitalWrite(LED_BLUE, LOW);
  digitalWrite(LED_GREEN, LOW);

  Wire.beginTransmission(0x2F);
  Wire.write(cnt);
  Wire.endTransmission();

  cnt += 24;

  if( cnt > 127 ) { cnt = 12;}
  
  delay(10);
  digitalWrite(LED_RED, HIGH);
  digitalWrite(LED_BLUE, HIGH);
  digitalWrite(LED_GREEN, HIGH);
  delay(200);
}
