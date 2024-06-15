#include <IRremote.h> // IR리모컨라이브러리

#define RECV_PIN A0   // IR 수신센서 포트설정
#define LED 13        //LED IO핀(내부 LED 사용)

IRrecv irrecv(RECV_PIN);
decode_results results; // 구조체정의

int on = 0; // 리모콘 수신신호
unsigned long last = millis();  // 아두이노 보드가 시작한 후 지난 시간(ms)

void setup()
{
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
    last = millis();      
    irrecv.resume(); // 다음 값을 수신
  }
}
