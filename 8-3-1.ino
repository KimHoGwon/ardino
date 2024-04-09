#define IN_R 13
#define IN_L 14
#define IN_RD 12 //high 후진, low 전진
#define IN_LD 12 //high 전진, low 후진

void setup() {
  Serial.begin(9600);
  pinMode(IN_R,OUTPUT);
  pinMode(IN_L,OUTPUT);
}
  pinMode(IN_RD,OUTPUT);
  pinMode(IN_LD,OUTPUT);

void loop() {

  Serial.println("go");

  digitalWrite(IN_RD,LOW);
  analogWrite(IN_R,127);

  digitalWrite(IN_LD,LOW);
  analogWrite(IN_L,127);
  delay(2000);
}
