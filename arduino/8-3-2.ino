#define IN_R 13
#define IN_L 14
#define IN_RD 12 //high 후진, low 전진
#define IN_LD 15 //high 전진, low 후진

void setup() {
  Serial.begin(9600);
  pinMode(IN_R,OUTPUT);
  pinMode(IN_L,OUTPUT);

  pinMode(IN_RD,OUTPUT);
  pinMode(IN_LD,OUTPUT);
}
void loop() {
  Serial.println("go");
  car_go(127);
  delay(2000);

}
  void car_go(int speed){

  digitalWrite(IN_RD,HIGH);
  analogWrite(IN_R,speed);

  digitalWrite(IN_LD,LOW);
  analogWrite(IN_L,speed);
  delay(2000);
  }