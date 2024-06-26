#define TRIG 5 // TRIG를 5로 선언
#define ECHO 6 // ECHO를 6으로 선언
#define BUZZER 13 // BUZZER를 9로 선언

void setup() {
  // put your setup code here, to run once:
 
  Serial.begin(9600);  // 초음파센서의 동작 상태를 확인하기 위해 시리얼 통신을 설정(전송속도 9600bps)

  pinMode(TRIG, OUTPUT);  //초음파 송신부를 출력 설정
  pinMode(ECHO, INPUT);   //초음파 수신부를 입력 설정
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(TRIG, LOW);
  //digitalWrite(ECHO, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH); 
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW); // 10ms만큼 출력

  unsigned long duration = pulseIn(ECHO, HIGH); // ECHO 핀에 입력 신호가 HIGH가 되는 시간을 측정

  //float distance = duration / 29.0 / 2.0; // 초음파는 1초당 340m를 이동(29us 당 1cm를 이동)
                                            // 따라서, 초음파의 이동 거리 = duration(왕복에 걸린시간) / 29 / 2
  float distance = ((float)(340 * duration) / 10000) / 2;

  Serial.print(distance);   // 측정된 거리 값를 시리얼 모니터에 출력합니다.
  Serial.println("cm");
  if(distance<=250)
  delay(distance*5);
  
  if(distance <= 30) // 거리가 15cm 이하일 때
  {
    digitalWrite(BUZZER, HIGH);
    delay(100);
  }
  else;
  digitalWrite(BUZZER, LOW);
  
  delay(100);
}
