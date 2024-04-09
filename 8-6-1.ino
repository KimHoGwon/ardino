#include "EEPROM.h"
#include "SSD1306Wire.h"
#include <WiFi.h>
#include <Wire.h>

#define SSID_EEP_ADDR 0
#define WiFi_NAME "gom"
#define PASSWORD "dked4589"

SSD1306Wire display(0x3c, 0, 2, GEOMETRY_128_32);

WiFiServer server(80); //wifi 포트 번호(생략가능)

void setup() {
  delay(3000);

  EEPROM.begin(10);
  String read_eep_ssid=EEPROM.readString(SSID_EEP_ADDR);

  if(read_eep_ssid != WiFi_NAME){

    EEPROM.writeString(SSID_EEP_ADDR, WiFi_NAME);
    EEPROM.commit();
  }
  //OLED 초기화
  display.init();

  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_16);
  display.setTextAlignment(TEXT_ALIGN_LEFT);

  //OLED 표시
  // read_eep_ssid=EEPROM.readString(SSID_EEP_ADDR);
  // display.clear();
  // display.drawString(0,0,read_eep_ssid);
  // display.display();

  // wifi 연결
  read_eep_ssid=EEPROM.readString(SSID_EEP_ADDR);
  const char* ssid = read_eep_ssid.c_str();
  WiFi.begin(ssid, PASSWORD);

  int wifi_status = 0;
  while(WiFi.status() != WL_CONNECTED){
    delay(500);

    //연결대기중
  if(wifi_status == 0){
    display.clear();
    display.drawString(0,0,"SSID: ");
    display.drawString(40,0,ssid);
    display.drawString(0,16,"PASS: ");
    display.drawString(45,16, PASSWORD);
    display.display();
  }
  else{
    display.clear();
    display.drawString(0,0,"SSID: ");
    display.drawString(40,0,ssid);
    display.drawString(120,0,".");
    display.drawString(0,16,"PASS: ");
    display.drawString(45,16, PASSWORD);
    display.display();

  }

    wifi_status = !wifi_status;
}
    //연결 성공
    display.clear();
    display.drawString(20,0,"IP address: ");
    display.drawString(0,16, ip2Str(WiFi.localIP()));
    display.display();


}

String ip2Str(IPAddress ip){
  String s="";
  for (int i=0; i<4; i++){
    s += i ? "." + String(ip[i]): String(ip[i]);
  }
  return s;
}

void loop() {
  String read_eep_ssid = EEPROM.readString(SSID_EEP_ADDR);
  
  delay(5000);
}
