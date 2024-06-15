void setup() {
  // put your setup code here, to run once:
  pinMode(11, OUTPUT); // 디지털 11번 핀을 출력으로 사용. PWM 출력 핀 사용
  pinMode(A3, INPUT); // 아날로그 3번 핀을 입력으로 사용.
}

void loop() {
  // put your main code here, to run repeatedly:
  int bright = analogRead(A3)/4; // int형 변수 bright를 선언하고, 3번 핀 analog 신호 입력값/4를 넣음.
                                // analog 입력값 범위 : 0~1023 (10비트 해상도)
                                // PWM 출력값 범위 : 0~255 (8비트 해상도)
                              
  analogWrite(11, bright); // 11번 핀에 bright값만큼 출력
}
