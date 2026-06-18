#include <Servo.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// ==== OLED SETTINGS ====
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// ==== PIN DEFINITIONS ====
#define TRIG_PIN 9
#define ECHO_PIN 10
#define BUZZER_PIN 3
#define BUTTON_PIN 4
#define SERVO_PIN 5

// ==== OBJECTS ====
Servo doorServo;

// ==== VARIABLES ====
long duration;
float distance;
bool personDetected = false;

// ==== DISTANCE THRESHOLD (cm) ====
const float DETECTION_DISTANCE = 50.0;

void setup() {
  Serial.begin(9600);

  // Pin modes
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  // Servo setup
  doorServo.attach(SERVO_PIN);
  doorServo.write(0);

  // OLED setup
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED init failed");
    for (;;);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Welcome");
  display.display();
}

void loop() {

  // Measure distance
  distance = getDistance();

  // Check if person is detected
  if (distance > 0 && distance <= DETECTION_DISTANCE) {
    personDetected = true;
    tone(BUZZER_PIN, 1000); // Buzzer ON (1 kHz)
  } else {
    personDetected = false;
    noTone(BUZZER_PIN);     // Buzzer OFF
  }

  // If person detected and button pressed
  if (personDetected && digitalRead(BUTTON_PIN) == LOW) {
    noTone(BUZZER_PIN); // Stop buzzer when opening door

    openDoor();
    delay(3000); // Keep door open for 3 seconds
    closeDoor();
  }

  delay(100);
}

// ==== FUNCTION: Measure distance using ultrasonic ====
float getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH, 30000);

  if (duration == 0)
    return -1;

  return (duration * 0.0343) / 2;
}

// ==== FUNCTION: Open door ====
void openDoor() {
  Serial.println("Opening Door...");

  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(10, 20);
  display.println("WELCOME");
  display.display();

  doorServo.write(90);
}

// ==== FUNCTION: Close door ====
void closeDoor() {
  Serial.println("Closing Door...");

  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("System Ready");
  display.display();

  doorServo.write(0);
}
