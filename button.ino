 int blueLED = 3;
int buttonPin = 2;
int buttonState = 0;
int state = 0;

void setup() {
 
 pinMode(blueLED, OUTPUT);
 pinMode(buttonPin, INPUT);
 // put your setup code here, to run once:

}

void loop() {
 buttonState = digitalRead(buttonPin);
 if ( buttonState == HIGH && state == 0)
 {
 
  digitalWrite(blueLED,HIGH);
  state = 1;
  
   // put your main code here, to run repeatedly:
  
 }
else 
{
  
  digitalWrite(blueLED,LOW);
  state = 0;
  
}

}
