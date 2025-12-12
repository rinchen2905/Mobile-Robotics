// Pins
const int trigPin = 3;
const int echoPin = 6;
const int buzzerPin = 12;

// Variables
long duration;
int distance;
int threshold = 20; // cm, distance to trigger buzzer

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600); // For debug
}

void loop() {
  // Trigger ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; // Convert to cm

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Check distance and activate buzzer
  if(distance < threshold){
    digitalWrite(buzzerPin, HIGH); // Buzzer ON
  } else {
    digitalWrite(buzzerPin, LOW);  // Buzzer OFF
  }

  delay(100); // Small delay
}
