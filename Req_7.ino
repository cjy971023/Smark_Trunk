int buzzerPin = 5;

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Open : 131Hz 1번 부저음 발생
  tone(buzzerPin, 131, 500); // 131 Hz
  delay(1000); // 1 sec delay
  noTone(buzzerPin); // OFF
  delay(1000); // 1 sec delay

  // Close : 262Hz 2번 부저음 발생
  tone(buzzerPin, 262, 500);
  delay(1000);
  noTone(buzzerPin);
  delay(300);
  
  tone(buzzerPin, 262, 500);
  delay(1000);
  noTone(buzzerPin);
  delay(1000);

  // Safety Mode : 손이 감지되면 300Hz 빠르게 5번 부저음 발생
  tone(buzzerPin, 300, 500);
  delay(300);
  noTone(buzzerPin);
  delay(300);

  tone(buzzerPin, 300, 500);
  delay(300);
  noTone(buzzerPin);
  delay(300);

  tone(buzzerPin, 300, 500);
  delay(300);
  noTone(buzzerPin);
  delay(300);

  tone(buzzerPin, 300, 500);
  delay(300);
  noTone(buzzerPin);
  delay(300);

  tone(buzzerPin, 300, 500);
  delay(300);
  noTone(buzzerPin);
  delay(1000);
}
