#include <Servo.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

Servo gateServo;

// Pins
#define TRIG 9
#define ECHO 10

#define SERVO_PIN 6

#define GREEN_LED 3
#define RED_LED 4


int carCount = 0;
int maxCars = 5;

long duration;
int distance;


// Function to read ultrasonic distance
int getDistance()
{
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG, LOW);

  duration = pulseIn(ECHO, HIGH);

  distance = duration * 0.034 / 2;

  return distance;
}


// OLED display
void showDisplay()
{
  display.clearDisplay();

  display.setTextSize(2);
  display.setTextColor(WHITE);

  display.setCursor(0,0);
  display.print("Cars: ");
  display.println(carCount);


  display.setCursor(0,30);
  display.print("Space: ");
  display.println(maxCars - carCount);


  display.display();
}


void setup()
{

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);


  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);


  gateServo.attach(SERVO_PIN);

  gateServo.write(0);   // Gate closed


  Serial.begin(9600);


  if(!display.begin(SSD1306_SWITCHCAPVCC,0x3C))
  {
    while(true);
  }


  showDisplay();

}



void loop()
{

 distance = getDistance();


 // Parking available
 if(carCount < maxCars)
 {
    digitalWrite(GREEN_LED,HIGH);
    digitalWrite(RED_LED,LOW);


    // Vehicle detected near gate
    if(distance < 15)
    {

      Serial.println("Vehicle detected");


      gateServo.write(90); // open gate
      delay(3000);


      gateServo.write(0);  // close gate


      // Check if vehicle actually entered
      delay(1000);


      distance = getDistance();


      if(distance > 15)
      {
        carCount++;

        if(carCount > maxCars)
        {
          carCount=maxCars;
        }

        showDisplay();
      }


    }

 }


 // Parking full
 else
 {

    digitalWrite(GREEN_LED,LOW);
    digitalWrite(RED_LED,HIGH);

    gateServo.write(0);

 }



 showDisplay();

 delay(500);

}
