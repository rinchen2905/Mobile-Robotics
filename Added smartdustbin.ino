#include <Servo.h>

#define TRIG_PIN 9
#define ECHO_PIN 10
#define SERVO_PIN 6

Servo dustbinServo;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  dustbinServo.attach(SERVO_PIN);
  dustbinServo.write(0);   // Lid closed

  Serial.begin(9600);
}

void loop() {
  long duration;
  float distance;

  // Send ultrasonic pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  // Read echo
  duration = pulseIn(ECHO_PIN, HIGH);

  // Calculate distance
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  // Open lid if object is within 20 cm
  if (distance > 0 && distance <= 20) {
    dustbinServo.write(90);  // Open lid
    delay(3000);             // Keep open for 3 seconds
    dustbinServo.write(0);   // Close lid
  }

  delay(200);
}
