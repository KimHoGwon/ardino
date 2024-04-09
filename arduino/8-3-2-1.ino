#define IN_R 13
#define IN_L 14
#define IN_RD 12 //high 후진, low 전진
#define IN_LD 15 //high 전진, low 후진

int speed = 0;

void setup() {
  Serial.begin(9600);
  pinMode(IN_R, OUTPUT);
  pinMode(IN_L, OUTPUT);

  pinMode(IN_RD, OUTPUT);
  pinMode(IN_LD, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    speed = Serial.parseInt();
  }
  if (speed >= 0 && speed <= 255) {
    Serial.print("go: ");
    Serial.println(speed);
    car_go(speed);
    delay(3000);

    Serial.print("go: ");
    Serial.println(speed);
    car_go(speed);
    delay(3000);

    Serial.print("left: ");
    Serial.println(speed);
    car_left(speed);
    delay(6000);

    Serial.print("back_left: ");
    Serial.println(speed);
    car_back_left(speed);
    delay(6000);

    Serial.print("right: ");
    Serial.println(speed);
    car_right(speed);
    delay(6000);

    Serial.print("back_right: ");
    Serial.println(speed);
    car_back_right(speed);
    delay(6000);

    Serial.print("back: ");
    Serial.println(speed);
    car_back(speed);
    delay(3000);

    Serial.print("back: ");
    Serial.println(speed);
    car_back(speed);
    delay(3000);
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
  analogWrite(IN_L, 0);
}

void car_right(int speed) {
  digitalWrite(IN_RD, LOW);
  analogWrite(IN_R, 0);

  digitalWrite(IN_LD, HIGH);
  analogWrite(IN_L, speed);
}

void car_back_left(int speed) {
  digitalWrite(IN_RD, HIGH);
  analogWrite(IN_R, speed);

  digitalWrite(IN_LD, HIGH);
  analogWrite(IN_L, 0);
}

void car_back_right(int speed) {
  digitalWrite(IN_RD, LOW);
  analogWrite(IN_R, 0);

  digitalWrite(IN_LD, LOW);
  analogWrite(IN_L, speed);
}
