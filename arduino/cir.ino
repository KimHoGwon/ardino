#define IN_R 13
#define IN_L 14
#define IN_RD 12 //high 후진, low 전진
#define IN_LD 15 //high 전진, low 후진
#include<Wire.h>
#include "SSD1306Wire.h"

SSD1306Wire display(0x3c, 0, 2, GEOMETRY_128_32);
int TIME_INTERVAL = 3000;


int speed = 255;
String rData;

void setup() {
  //Serial.begin(9600);
  pinMode(IN_R, OUTPUT);
  pinMode(IN_L, OUTPUT);

  pinMode(IN_RD, OUTPUT);
  pinMode(IN_LD, OUTPUT);

  //Serial.println();
  //Serial.println();

  display.init();

  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);
}

void loop() {
  if (Serial.available() > 0) {
    //speed = Serial.parseInt();
  }
  if (speed >= 0 && speed <= 255) {
    delay(1000);

    rData="left: ";
    display.clear();
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.drawString(0,10,rData + String(speed));
    display.display();
    Serial.println(speed);
    car_left(speed);
    delay(TIME_INTERVAL*2);

    rData="back_left: ";
    display.clear();
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.drawString(0,10,rData + String(speed));
    display.display();
    Serial.println(speed);
    car_back_left(speed);
    delay(TIME_INTERVAL*2);
 
    rData="right: ";
    display.clear();
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.drawString(0,10,rData + String(speed));
    display.display();
    Serial.println(speed);
    car_right(speed);
    delay(TIME_INTERVAL*2);

    rData="back_right: ";
    display.clear();
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.drawString(0,10,rData + String(speed));
    display.display();
    Serial.println(speed);
    car_back_right(speed);
    delay(TIME_INTERVAL*2);

    rData="back_left: ";
    display.clear();
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.drawString(0,10,rData + String(speed));
    display.display();
    Serial.println(speed);
    car_back_left(speed);
    delay(TIME_INTERVAL*2);

    rData="left: ";
    display.clear();
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.drawString(0,10,rData + String(speed));
    display.display();
    Serial.println(speed);
    car_left(speed);
    delay(TIME_INTERVAL*2);

    rData="back_right: ";
    display.clear();
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.drawString(0,10,rData + String(speed));
    display.display();
    Serial.println(speed);
    car_back_right(speed);
    delay(TIME_INTERVAL*2);

    rData="right: ";
    display.clear();
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.drawString(0,10,rData + String(speed));
    display.display();
    Serial.println(speed);
    car_right(speed);
    delay(TIME_INTERVAL*2);

    String rData="go: ";
    display.clear();
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.drawString(0,10,rData + String(speed));
    display.display();
    Serial.println(speed);
    car_go(speed);
    delay(TIME_INTERVAL);

    rData="turn: ";
    display.clear();
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.drawString(0,10,rData + String(speed));
    display.display();
    Serial.println(speed);
    car_turn(speed);
    delay(TIME_INTERVAL/2);

    rData="right: ";
    display.clear();
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.drawString(0,10,rData + String(speed));
    display.display();
    Serial.println(speed);
    car_right(speed);
    delay(TIME_INTERVAL*12);
  }
}

void car_go(int speed) {
  digitalWrite(IN_RD, LOW);
  analogWrite(IN_R, speed);

  digitalWrite(IN_LD, HIGH);
  analogWrite(IN_L, speed);
}

void car_back(int speed) {
  digitalWrite(IN_RD, HIGH);
  analogWrite(IN_R, speed);

  digitalWrite(IN_LD, LOW);
  analogWrite(IN_L, speed);
}

void car_left(int speed) {
  digitalWrite(IN_RD, LOW);
  analogWrite(IN_R, speed);

  digitalWrite(IN_LD, HIGH);
  analogWrite(IN_L, speed/4);
}

void car_right(int speed) {
  digitalWrite(IN_RD, LOW);
  analogWrite(IN_R, speed/4);

  digitalWrite(IN_LD, HIGH);
  analogWrite(IN_L, speed);
}

void car_back_left(int speed) {
  digitalWrite(IN_RD, HIGH);
  analogWrite(IN_R, speed);

  digitalWrite(IN_LD, LOW);
  analogWrite(IN_L, speed/4);
}

void car_back_right(int speed) {
  digitalWrite(IN_RD, HIGH);
  analogWrite(IN_R, speed/4);

  digitalWrite(IN_LD, LOW);
  analogWrite(IN_L, speed);
}

void car_turn(int speed) {
  digitalWrite(IN_RD, HIGH);
  analogWrite(IN_R, speed);

  digitalWrite(IN_LD, HIGH);
  analogWrite(IN_L, speed);
}

void car_cir(int speed) {
  digitalWrite(IN_RD, LOW);
  analogWrite(IN_R, speed/4);

  digitalWrite(IN_LD, HIGH);
  analogWrite(IN_L, speed);
}