void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT); // 13번 핀을 출력으로 사용
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13, HIGH); // 13번 핀에 HIGH(5V) 출력
  delay(1000);            // 1초 (1000ms) 지연
  digitalWrite(13, LOW);  // 13번 핀에 LOW(0V) 출력
  delay(1000);            // 1초 (1000ms) 지연
}
