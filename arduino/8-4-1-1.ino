#include<Wire.h>
#include "SSD1306Wire.h"

SSD1306Wire display(0x3c, 0, 2, GEOMETRY_128_32);


void setup() {

  Serial.begin(115200);
  Serial.println();
  Serial.println();

  display.init();

  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);

}

void loop() {
  if (Serial.available() > 0) {
    String rData=Serial.readStringUntil('\n');
    display.clear();
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.drawString(0,10,"rData");
    display.display();
    delay(2000);
  }

}
