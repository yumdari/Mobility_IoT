#include "DHT.h" // DHT 온습도 센서 헤더파일 추가

//int DHTPIN = 3;// int 크기만큼 메모리 할당

#define DHTPIN 3 // DHTPIN을 3이라고 정의
                 // DHTPIN이라는 단어를 모두 3으로 바꿈. 메모리 할당 X

#define DHTTYPE DHT11 // DHT 시리즈 중 11을 선택

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // Serial 통신 시작. 보드레이트는 9600으로 설정

  dht.begin(); //
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(2000); 센싱을 위한 2초 딜레이
  
  float humi = dht.readHumidity();    // float형 변수 humi를 선언하고, 여기에 습도 측정값을 넣음
  float temp = dht.readTemperature(); // float형 변수 temp를 선언하고, 여기에 온도 측정값을 넣음

  float celc = dht.computeHeatIndex(temp, humi, false); // 보정된 섭씨 온도 값을 가져옴

   Serial.print("Humidity: ");
   Serial.print(humi);
   Serial.print(" %\t");
   Serial.print("Temperature: ");
   Serial.println(temp);
   
  if(temp >= 26) || (humi >= 70)
  {
  }
  
  }
}
