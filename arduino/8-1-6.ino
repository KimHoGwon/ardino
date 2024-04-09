void setup() {
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()>0)
  {
    char sData=Serial.read();
    if(sData=='a')Serial.println("a ok");
    else if(sData=='b')Serial.println("b ok");
    else if(sData=='c')Serial.println("c ok");
  }
}
