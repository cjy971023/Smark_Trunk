/*sensor0가 오픈하기 위한 거리 측정 센서,
sensor1가 클로즈하기 위한 거리 측정 센서

이에 따른 측정 거리는 각각 distance0, distance1임*/

#define trigPin1 50
#define echoPin1 51

/*Ultrasonic Sensor (HC-SR04)*/
//ultrasonic speed : 340m/s
float duration1, distance1;
void read_distance1(void);


void setup() {

  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);

  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  SerialASC.begin(9600);
}

void loop() {
  // sensor0가 발 센서, sensor1가 손 센서
  read_distance1();

  if((distance1<5) && (distance1>0)) // BLUE
  {
    digitalWrite(13, HIGH); // sets the digital pin 13 on
    delay(1000); // waits for a second
    digitalWrite(13, LOW); // sets the digital pin 13 off
    delay(1000); // waits for a second
  }
}

void read_distance1(void)
{
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW); 
  // Echo 핀으로 들어온 펄스 시간 (us) 측정 
  //pulseIn(pin, value, timeout)
  //pin :  the number of the Arduino pin on which you want to read the pulse.
  //value: type of pulse to read: either HIGH or LOW
  //timeout (optional): the number of microseconds to wait for the pulse to start; 
  // --> default is one second, unsigned long
  duration1 = pulseIn(echoPin1, HIGH, 11000); //time[us]
  distance1 = ((float)(duration1)*0.34/10)/2; //time[us]*speed[cm/us]
   //printf("sensor1: ");
  SerialASC.println("sensor1: ");
  SerialASC.println(distance1);
  /*
  if ((distance < 7.0f) | (distance > 400))
  {
    SerialASC.println("Distance Caution ");
  }
  else
  {
    SerialASC.print("Distance: ");
    SerialASC.println(distance);
  }
  */
  delay(100);
}


