void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT); // 13번 핀을 출력으로 사용.
  pinMode(3, INPUT); // 3번 핀을 입력으로 사용. analog 입력 핀 사용
}

void loop() {
  // put your main code here, to run repeatedly:
  int light = analogRead(3); // int형 변수 bright를 선언하고, 3번 핀 analog 신호 입력값을 대입.
                             // analog 입력값 범위 : 0~255 (8비트 해상도)
                              
  if(light < 100) // light 값이 100 미만이면 (어두워지면) 아래 동작 실행
  {
    digitalWrite(13, HIGH) // 13번 핀에 HIGH(5V) 출력
  }
  else // light 값이 100 이상이면 아래 동작 실행 
  digitalWrite(13, LOW) // 13번 핀에 LOW(0V) 출력
}
