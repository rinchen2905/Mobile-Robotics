const int Trig = 9;
const int Echo = 10;

float duration, distance;

void setup() {
  pinMode(Trig,OUTPUT);
  pinMode(Echo,INPUT);
  Serial.begin(9600);
  // put your setup code here, to run once:
}

void loop() {
  digitalWrite(Trig,LOW); // makes sure the trigger pin starts from LOW
  delayMicroseconds(2);
  digitalWrite(Trig,HIGH); 
  delayMicroseconds(10);
  digitalWrite(Trig,LOW);


  duration = pulseIn(Echo,HIGH);

  distance = (duration * 0.034)/2;

  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);
  // put your main code here, to run repeatedly:

}
