#define redLed 9
#define greenLed 10
#define blueLed 11
void setup()
{
// initialize serial communication at 9600 bits per second:
pinMode(redLed, OUTPUT);
pinMode(blueLed, OUTPUT);
pinMode(greenLed, OUTPUT);
}
void loop()
{
// turn the LED on (HIGH is the voltage level), Safety Mode
digitalWrite(redLed, HIGH); 
delay(1000);
digitalWrite(redLed, LOW);
delay(1000);

// turn the LED on (HIGH is the voltage level), Close Mode
digitalWrite(blueLed, HIGH);
delay(1000);
digitalWrite(blueLed, LOW);
delay(1000);

// turn the LED on (HIGH is the voltage level), Open Mode
digitalWrite(greenLed, HIGH);
delay(1000);
digitalWrite(greenLed, LOW);
delay(1000);
}

// 단위테스트에서는 정상 작동하지만 통합 시 아두이노 모터쉴드의 9,11번 핀이 각각 brake A, PWM B로 설정되어있어 해당 기능 사용 시 Red, Blue RGB는 사용이 불가능할 것으로 예상
// 특히, Blue RGB에 해당하는 11번 PWM B 핀은 스텝모터 구동에 반드시 필요하므로 RGB 제어가 불가능함
