#include <DHT11.h> // DHT11 라이브러리 포함
#define PIN A0     // PIN을 A0로 선언
DHT11 dht11(PIN); // DHT11을 A0 핀으로 설정

void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600); // Serial 통신을 위한 초기화. 보드레이트는 9600으로 설정
   Serial.println("Start");
   pinMode(13, OUTPUT); // 13번 핀을 출력 핀으로 설정
}

void loop() {
  // put your main code here, to run repeatedly:
  int err = 0; // 에러 검출용 변수 선언
  float temp, humi = 0; // 실수형 변수 (온도, 습도) 선언
  if((err = dht11.read(humi, temp)) == 0) // DHT.h 함수안에 dht11이라는 메소드 사용하여 현재 온습도 값을 자동으로 계산
                                          // 계산후 현재 온습도가 데이터가 나오는지 아닌지 판단한 리턴값을 result 변수에 저장
                                          //   dht11메소드 에서는 온습도가 잘 감지되면 0을 리턴
  {
    Serial.print("temperature:"); // 온도 출력
    Serial.print(temp);
    Serial.print(" humidity:"); // 습도 출력
    Serial.print(humi);
    Serial.println();
  }
  else // 에러 발생 시
  {
    Serial.println();
    Serial.print("Error No :");
    Serial.print(err);
    Serial.println();    
  }
  if((temp >= 30)||(humi >= 60)) // 온도 30도 또는 습도 60% 이상일 때 동작
  {
    digitalWrite(13,HIGH);
  }
  else 
  digitalWrite(13,LOW);
  delay(DHT11_RETRY_DELAY); // 일반적인 딜레이 값이 아니라, DHT11에서 권장하는 딜레이함수를 사용해줘야 정상적인 값이 나옴.
                            // DHT11 라이브러리안에 미리 설정되어있는 딜레이시간을 적용
}
