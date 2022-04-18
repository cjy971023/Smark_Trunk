int volatile ADresult;

/*** Core 0 ***/

void setup() {

  SerialASC.begin(9600);
  analogReadResolution(12);

  pinMode(12, OUTPUT);    // RED LED
  pinMode(13, OUTPUT);    // BLUE LED

}


void loop() {
  // put your main code for core 0 here, to run repeatedly:
  //

   ADresult=ReadAD0();

if(ADresult<1400)
{
    digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(100); // wait for a 1/10 second.
    digitalWrite(13, LOW);   // turn the LED on (HIGH is the voltage level)
    delay(100); // wait for a 1/10 second.
}
else if((ADresult>1500)&&(ADresult<2800))
{
    digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(100); // wait for a 1/10 second.  
    digitalWrite(12, LOW);   // turn the LED on (HIGH is the voltage level)
    delay(100); // wait for a 1/10 second.
}
else if(ADresult>2900)
{
    digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(100); // wait for a 1/10 second.
    digitalWrite(13, LOW);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(12, LOW);   // turn the LED on (HIGH is the voltage level)
    delay(100); // wait for a 1/10 second.
}
else
{
  
}
   /*
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  //
  delay(100); // wait for a 1/10 second.
  SerialASC.print("Testing analog in\n\r");
  delay(100); // wait for a 1/10 second.
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  //
  //                           // Aansluitngen AD7..0 verwisseld in documentatie ... vermelding op board klopt
        // Als niks aangesloten dan ongeveer 520 als waarde 5volt = 1023/1024
  ADresult[1]=ReadAD1();
  //
*/
  SerialASC.print(":");  
  SerialASC.print(ADresult,DEC);
  SerialASC.print("\n\r");
}

