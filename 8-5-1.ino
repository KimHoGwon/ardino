#include "EEPROM.h"

#define SSID_EEP_ADDR 0

void setup() {
Serial.begin(115200);
delay(3000);

EEPROM.begin(10);
String eep_write_string="eep_test";
EEPROM.writeString(SSID_EEP_ADDR, eep_write_string);
EEPROM.commit();

Serial.println("eep write finish");

}

void loop() {
  // put your main code here, to run repeatedly:

}
