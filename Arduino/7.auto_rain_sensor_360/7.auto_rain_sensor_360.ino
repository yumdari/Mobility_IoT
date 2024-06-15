#include<Servo.h>

Servo servo;

int water_sensor = A0; // 수위센서 아날로그 입력 핀
int sensor_val; // 수위 센서 값

int value = 0; // 서보모터 조절 변수

void setup() {
  // put your setup code here, to run once:

  servo.attach(11);
  
  Serial.begin(9600);  // 수위 센서의 동작 상태를 확인하기 위해 시리얼 통신을 설정(전송속도 9600bps)
}

void loop() {
  // put your main code here, to run repeatedly:

  sensor_val = analogRead(water_sensor); // 센서의 아날로그 값 읽어오기

  Serial.print(sensor_val);   // 측정된 수위를 시리얼 모니터에 출력합니다.

  delay(100); //  0.1초 대기

  //if(sensor_val > 400) // 센서 값이 400 이상이라면
  {
    value += 90; // value 값 30 증가
    servo.write(value); // value 값 각도로 회전
    delay(500);
   // if(value >= 180) // value가 180도 이상 이면 0으로 초기화
    {
   //   value = 0;
    }
  }
 // else
  {
   // value = 0;
  }
}
