// left motors
int ENA = 5;   // PWM
int IN1 = 6;
int IN2 = 7;


void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);  
}

void loop() {
  forward(3000);
  delay(2000);
  backward(5000);
  delay(2000);
  stopAll();
  delay(2000);
}

void forward(int speed) {
  // Left motors
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 400);

  
}

void backward(int speed) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 400);

  
}
void stopAll() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  
}
