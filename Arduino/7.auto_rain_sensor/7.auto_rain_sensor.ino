int Sensor = A0;
int Sensor_val;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  // 수위 센서의 동작 상태를 확인하기 위해 시리얼 통신을 설정(전송속도 9600bps)
}

void loop() {
  // put your main code here, to run repeatedly:

  Sensor_val = analogRead(Sensor); // 센서의 아날로그 값 읽어오기

  Serial.print(Sensor_val);   // 측정된 수위를 시리얼 모니터에 출력합니다.

}
