#define LED_BUILTIN 4

int value; // 변수 선언
int i = 0; // 변수 선언 및 초기화
const int TIME_INTERVAL = 1000; // 상수 선언
int weight = 1; // 변수 선언 및 초기화

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN,OUTPUT);
}

void loop() {
  value = map(i,0,2000,0,255);
  analogWrite(LED_BUILTIN,value);
  delay(TIME_INTERVAL);

  i=i+weight;
  
  if(abs(i)>2000 || abs(i) ==0){
    weight=weight*(-1);
  }
}