
#define Button 2
#define LED 13
#define sendsignal 7

 
void setup()
{
  pinMode(Button, INPUT); //버튼은 입력으로 설정
  pinMode(LED, OUTPUT); //LED는 출력으로 설정
  pinMode(sendsignal, OUTPUT); //보내는 신호는 출력으로 설정
}
void loop()
{
  if (digitalRead(Button) == LOW) // 누른거
  {
    //digitalWrite(LED,HIGH); // LED
    digitalWrite(sendsignal,HIGH);

    digitalWrite(LED,HIGH); // LED
    delay(100);
    digitalWrite(LED,LOW); // LED
    delay(100);
   
  }
  else // 안누른거
  {
   
   digitalWrite(sendsignal,LOW);

   digitalWrite(LED,LOW);// LED 켜짐
    delay(100);
  }

//delay(100);

}



