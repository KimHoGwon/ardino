#include "EEPROM.h"
#include "SSD1306Wire.h"        // legacy: #include "SSD1306.h"
#include <WiFi.h>
#include <Wire.h>   

#define SSID_EEP_ADDR 0
#define WiFi_NAME "gom"
#define PASSWORD "dked4589"
#define LED_BUILTIN 4

SSD1306Wire display(0x3c, 0, 2, GEOMETRY_128_32);

WiFiServer server(80);  //포트번호 설정 (생략가능)

void setup() {


  Serial.begin(115200);
  pinMode(LED_BUILTIN,OUTPUT);
  delay(3000);

  EEPROM.begin(10);
  String read_eep_ssid = EEPROM.readString(SSID_EEP_ADDR);
  
  if(read_eep_ssid != WiFi_NAME){ 
    EEPROM.writeString(SSID_EEP_ADDR, WiFi_NAME);
    EEPROM.commit();
  }

  //OLED 초기화
  display.init();

  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_16);
  display.setTextAlignment(TEXT_ALIGN_LEFT);

  // //OLED 표시
  // read_eep_ssid = EEPROM.readString(SSID_EEP_ADDR);
  // display.clear();
  // display.drawString(0,0,read_eep_ssid);
  // display.display();

  
  //wifi 연결
  read_eep_ssid = EEPROM.readString(SSID_EEP_ADDR);
  const char* ssid = read_eep_ssid.c_str();
  WiFi.begin(ssid, PASSWORD);

  int wifi_status = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    //연결대기중
    if(wifi_status == 0){
      display.clear();
      display.drawString(0, 0, "SSID:");
      display.drawString(40, 0, ssid);
      display.drawString(0, 16, "PASS:");
      display.drawString(45, 16, PASSWORD);
      display.display();
    }
    else{
      display.clear();
      display.drawString(0, 0, "SSID:");
      display.drawString(40, 0, ssid);
      display.drawString(120, 0, ".");
      display.drawString(0, 16, "PASS:");
      display.drawString(45, 16, PASSWORD);
      display.display();
    }
    
    wifi_status = !wifi_status;
  }

  //연결 성공.
  display.clear();
  display.drawString(20, 0, "IP address:");
  display.drawString(0, 16, ip2Str(WiFi.localIP()));
  display.display();

  server.begin();  // 서버 동작
}

void loop() {
  WiFiClient client = server.available();   // 새로운 클라이언트 생성  
  if (client) {                             // 클라이언트가 만들어지고
    Serial.println("create client");
    String currentLine = "";                // 클라이언트에서 받을 문자열 변수준비

    while (client.connected()) {            // 연결될 때까지...
      if (client.available()) {             // 클라이언트에서 문자를 받으면
        char c = client.read();             // 문자를 byte 단위로 읽고, 문자로 저장
        if (c == '\n') {                    // 문자가 개행문자이면..
           break;                           // while loop를 종료
        } else if (c != '\r') {
          currentLine += c;     
        }
      }
    }

    Serial.println(currentLine);
    Serial.println(currentLine.indexOf("/"));

    int index = currentLine.indexOf("/");
    int num = currentLine.substring(index+1,index+3).toInt();

    Serial.println(num);

    
    client.stop();
    Serial.println("Client Disconnected.");
  }

}



String ip2Str(IPAddress ip){
  String s="";
  for (int i=0; i<4; i++) {
    s += i  ? "." + String(ip[i]) : String(ip[i]);
  }
  return s;
}