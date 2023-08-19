void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT); // 13번 핀을 출력으로 사용
  pinMode(3, INPUT); // 3번 핀을 입력으로 사용
}

void loop() {
  // put your main code here, to run repeatedly:
  int break = digitalRead(3); // int형 변수 break를 선언하고, 3번 핀 digital 신호 입력값을 대입
                              // 0(FALSE) : 버튼 안눌림 - 브레이크 작동
                              // 1(TRUE) : 버튼 눌림 - 브레이크 미작동

  if(break == 0) // 만약 브레이크를 작동했다면(버튼이 떼졌다면) 아래 동작 실행
  {
    digitalWrite(13, HIGH) // 13번 핀에 HIGH(5V) 출력
  }
  else // 브레이크 미작동 시(버튼이 눌린 상태) 아래 동작 실행
  digitalWrite(13, LOW); // 13번 핀에 LOW(0V) 출력
}
