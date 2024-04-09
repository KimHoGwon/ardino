#define LED_BUILTIN 4

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN,OUTPUT);

}

void loop() {
  digitalWrite(LED_BUILTIN, 5);
  delay(80);
  digitalWrite(LED_BUILTIN, LOW);
  delay(90);

  digitalWrite(LED_BUILTIN, 5);
  delay(80);
  digitalWrite(LED_BUILTIN, LOW);
  delay(90);

  digitalWrite(LED_BUILTIN, 5);
  delay(80);
  digitalWrite(LED_BUILTIN, LOW);
  delay(200);

  digitalWrite(LED_BUILTIN, 5);
  delay(200);
  digitalWrite(LED_BUILTIN, LOW);
  delay(90);

  digitalWrite(LED_BUILTIN, 5);
  delay(200);
  digitalWrite(LED_BUILTIN, LOW);
  delay(90);

  digitalWrite(LED_BUILTIN, 5);
  delay(200);
  digitalWrite(LED_BUILTIN, LOW);
  delay(110);

  digitalWrite(LED_BUILTIN, 5);
  delay(80);
  digitalWrite(LED_BUILTIN, LOW);
  delay(90);

  digitalWrite(LED_BUILTIN, 5);
  delay(80);
  digitalWrite(LED_BUILTIN, LOW);
  delay(90);

  digitalWrite(LED_BUILTIN, 5);
  delay(80);
  digitalWrite(LED_BUILTIN, LOW);
  delay(800);


}
