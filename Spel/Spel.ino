#include <Servo.h>


const int ledPin = 13;
const int joyPin1 = A0;  // slider variable connected to analog pin 0
const int joyPin2 = A1;  // slider variable connected to analog pin 1
const int SW_PIN = 2;    // Arduino pin connected to SW  pin


int value1 = 0;   
int value2 = 0;  
int pos = 0;     


Servo myservo1;  
Servo myservo2;

void setup() {
  pinMode(ledPin, OUTPUT); 
  pinMode(SW_PIN, INPUT_PULLUP);

  myservo1.attach(9);  
  myservo2.attach(5)

  Serial.begin(9600);
}

int treatValue(int data) {
  return (data * 9 / 1024) + 48;
}

void loop() {

  value1 = analogRead(joyPin1);
  value2 = analogRead(joyPin2);

  myservo.write(map(value2, 0, 1023, 0, 180));
  myservo2.write(map(value2, 1023, 0, 180, 0)); 

  Serial.print(digitalRead(SW_PIN));
  Serial.print("   ");
  Serial.print(value1);
  Serial.print("   ");
  Serial.println(value2);

  if (digitalRead(SW_PIN) == 0) {

    digitalWrite(ledPin, HIGH);

  } else {
    digitalWrite(ledPin, LOW);
  }
}
