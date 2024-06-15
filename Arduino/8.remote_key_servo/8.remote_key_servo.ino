#include <IRremote.h> // IR리모컨 라이브러리
#include <Servo.h>    // 서보모터 라이브러리

#define RECV_PIN A0   // IR 수신센서 포트설정
#define LED 13        //LED IO핀(내부 LED 사용)
#define SERVO 11
#define SERVO360
//#define SERVO180

#define ZERO  0xFF6897
#define ONE   0xFF30CF
#define TWO   0xFF18E7

IRrecv irrecv(RECV_PIN);  // IR센서 객체 생성 
decode_results results;   // 구조체정의

Servo myservo;  // 서보모터 객체를 myservo로 생성

int on = 0; // 리모콘 수신신호
unsigned long last = millis();  // 아두이노 보드가 시작한 후 지난 시간(ms)

void setup()
{
  myservo.attach(11);  // 서보모터를 디지털 11번핀에 연결
  
  pinMode(LED, OUTPUT); // 디지털 13번핀을 출력으로 지정
  Serial.begin(9600);   //시리얼 통신 시작. 보드레이트를 9600bps로 지정
  irrecv.enableIRIn();  // 리모컨 수신 시작
}

void loop()
{
  if (irrecv.decode(&results)) //IR리모컨 라이브러리 호출
  {
    if (millis() - last > 250) //수신신호 결정
    {
      on = !on; // 수신신호 반전
      digitalWrite(LED, on ? HIGH : LOW); //리모컨 수신시 LED(13)로 표시
    }
    Serial.println(results.value, HEX);   //리모컨 수신코드를 출력

    switch(results.value)
    {
      case ONE : 
      /*360도 서보*/
#ifdef SERVO360
      Serial.println("360도 서보 문열림");  
      myservo.write(180); // 역방향으로 최고속도 회전
      delay(1500); // 1.5초 동작
      myservo.write(92); // 정지
      delay(500);  // 0.5초 동작
      break;
#endif

      /*180도 서보*/
#ifdef SERVO180
      Serial.println("180도 서보 문열림");  
      for(int angle = 0; angle <= 180; angle++)
      {
        myservo.write(angle);
      }
      break;
#endif
      case TWO :
      /*360도 서보*/
#ifdef SERVO360
      myservo.write(0);  // 정방향으로 최고속도 회전
      delay(1500); // 1.5초동작
      myservo.write(92); // 정지
      delay(500);  // 0.5초 동작
      break;
#endif

      /*180도 서보*/
#ifdef SERVO180
      for(int angle = 180; angle >= 0; angle--)
      {
        myservo.write(angle);
      }
      break;
#endif
    }

    last = millis();
    irrecv.resume(); // 다음 값을 수신
  }
}
