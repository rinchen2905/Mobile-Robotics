#include <Servo.h>

Servo myservo;

const int Trig = 11;
const int Echo = 10;

float duration, distance;

void setup() {
  myservo.attach(12);
  pinMode(Trig,OUTPUT);
  pinMode(Echo,INPUT);
  Serial.begin(9600);
}
void loop() {
  
  for (int angle = 0; angle <= 180; angle++){
    myservo.write(angle); 
    delay(30);
    distance = getDistance();
   
    Serial.print(angle);
    Serial.print(","); 
    Serial.print(distance);
  }

  for (int angle = 180; angle >= 0; angle--){
    myservo.write(angle);
    delay(30);
    distance = getDistance();

    Serial.print(angle);
    Serial.print(",");
    Serial.print(distance);
  // put your main code here, to run repeatedly:
}

}

int getDistance(){
  digitalWrite(Trig,LOW);
  delayMicroseconds(2);
  digitalWrite(Trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig,LOW);

  duration = pulseIn(Echo,HIGH);

  distance = (duration * 0.034)/2;
  return (duration * 0.034 / 2);
}
