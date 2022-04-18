
#define LED 13
#define LED_RED 12
#define recievesignal 7 

void setup()
{
  
  pinMode(LED, OUTPUT); //LED는 출력으로 설정
  pinMode(LED_RED, OUTPUT); //LED는 출력으로 설정
  pinMode(recievesignal, INPUT); 
}

void loop()
{
  if (digitalRead(recievesignal) == HIGH) // 누른거
  {
     digitalWrite(LED,HIGH); // LED
    delay(100);
    digitalWrite(LED,LOW); // LED
    delay(100);
   
  }
  else // 안누른거
  {
    digitalWrite(LED_RED,HIGH); // LED
    delay(100);
    digitalWrite(LED_RED,LOW); // LED
    delay(100);
 
  }
  
  //delay(100);


}

