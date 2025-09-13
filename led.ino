int redLED = 6;
int blueLED = 5;
int greenLED = 9;
void setup() {
  pinMode(redLED,OUTPUT);
  pinMode(blueLED,OUTPUT);
  pinMode(greenLED,OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
 digitalWrite(redLED,HIGH);
 delay(500);
 digitalWrite(redLED,LOW);
 delay(500);
 digitalWrite(blueLED,HIGH);
 delay(500);
 digitalWrite(blueLED,LOW);
 delay(500);
 digitalWrite(greenLED,HIGH);
 delay(500);
 digitalWrite(greenLED,LOW);
 delay(500);



 // put your main code here, to run repeatedly:

}
