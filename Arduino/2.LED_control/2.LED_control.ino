void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT); // 13번 핀을 출력으로 사용. PWM 출력 핀 사용
  pinMode(3, INPUT); // 3번 핀을 입력으로 사용. analog 입력 핀 사용
}

void loop() {
  // put your main code here, to run repeatedly:
  int bright = analogRead(3); // int형 변수 bright를 선언하고, 3번 핀 analog 신호 입력값을 넣음.
                              // analog 입력값 범위 : 0~255 (8비트 해상도)
                              
  analogWrite(13, bright); // 13번 핀에 bright값만큼 출력
}
