/*sensor0가 오픈하기 위한 거리 측정 센서,
sensor1가 클로즈하기 위한 거리 측정 센서

이에 따른 측정 거리는 각각 distance0, distance1임*/
#define trigPin0 48
#define echoPin0 49

/*Ultrasonic Sensor (HC-SR04)*/
//ultrasonic speed : 340m/s
float duration0, distance0;

void read_distance0(void);


void setup() {
  pinMode(trigPin0, OUTPUT);
  pinMode(echoPin0, INPUT);

  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  SerialASC.begin(9600);
}

void loop() {
  // sensor0가 발 센서, sensor1가 손 센서
  read_distance0();

  if((distance0<5) && (distance0>0)) // RED
  {
    digitalWrite(12 , HIGH); // sets the digital pin 1 2 on
    delay(1000); // waits for a second
    digitalWrite(12 , LOW); // sets the digital pin 1 2 off
    delay(1000); // waits for a secon
  }
}


void read_distance0(void)
{
  digitalWrite(trigPin0, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin0, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin0, LOW); 
  // Echo 핀으로 들어온 펄스 시간 (us) 측정 
  //pulseIn(pin, value, timeout)
  //pin :  the number of the Arduino pin on which you want to read the pulse.
  //value: type of pulse to read: either HIGH or LOW
  //timeout (optional): the number of microseconds to wait for the pulse to start; 
  // --> default is one second, unsigned long
  duration0 = pulseIn(echoPin0, HIGH, 11000); //time[us]
  distance0 = ((float)(duration0)*0.34/10)/2; //time[us]*speed[cm/us]
  SerialASC.println("sensor0: ");
  SerialASC.println(distance0);
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

