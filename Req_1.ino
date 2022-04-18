// Include the Stepper library:
#include <Stepper.h>
// Define number of steps per revolution:
const int stepsPerRevolution = 200;
// Give the motor control pins names:
#define pwmA 3
#define pwmB 11
#define brakeA 9
#define brakeB 8
#define dirA 12
#define dirB 13

int n = 6;

// Initialize the stepper library on the motor shield:
Stepper myStepper = Stepper(stepsPerRevolution, dirA, dirB);

void stepmotor_open(void);

void setup() {
  // put your setup code here, to run once:

  // Stepper 모터 setup
  pinMode(pwmA, OUTPUT);
  pinMode(pwmB, OUTPUT);
  pinMode(brakeA, OUTPUT);
  pinMode(brakeB, OUTPUT);
  digitalWrite(pwmA, HIGH);
  digitalWrite(pwmB, HIGH);
  digitalWrite(brakeA, LOW);
  digitalWrite(brakeB, LOW);
  myStepper.setSpeed(10); // Set the motor speed (RPMs):

}

void loop() {
  // put your main code here, to run repeatedly:

 
    for (int i = 0; i < 6; i++){
    stepmotor_open();          
    }
    delay(1000);
}

void stepmotor_open(){
  myStepper.step(6);  // 10도
}

