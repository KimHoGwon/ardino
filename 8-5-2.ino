#include "EEPROM.h"

#define SSID_EEP_ADDR 0

void setup() {
Serial.begin(115200);
delay(3000);

EEPROM.begin(10);
String read_eep_ssid=EEPROM.readString(SSID_EEP_ADDR);

Serial.print("read data: ");
Serial.println(read_eep_ssid);

}

void loop() {
  // put your main code here, to run repeatedly:

}
