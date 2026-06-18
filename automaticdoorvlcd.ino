#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

Servo doorServo;
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Ultrasonic pins
const int trigPin = 9;
const int echoPin = 10;

// Other components
const int ledPin = 7;
const int buttonPin = 2;
const int servoPin = 6;

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  doorServo.attach(servoPin);
  doorServo.write(0); // Door closed

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Automatic Door");
  delay(2000);
  lcd.clear();

  Serial.begin(9600);
}

void loop() {

  // Measure distance
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  // Person detected within 30 cm
  if (distance > 0 && distance <= 30) {

    digitalWrite(ledPin, HIGH);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Welcome");
    delay(3000);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Press Button");

    // Wait for button press
    while (digitalRead(buttonPin) == HIGH) {
      // Waiting...
    }

    // Open door
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Door Opening");

    doorServo.write(90);
    delay(5000);

    // Close door
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Door Closing");

    doorServo.write(0);
    delay(2000);

    lcd.clear();
  }
  else {
    digitalWrite(ledPin, LOW);

    lcd.setCursor(0, 0);
    lcd.print("No Person      ");
    lcd.setCursor(0, 1);
    lcd.print("Detected       ");
  }

  delay(200);
}
