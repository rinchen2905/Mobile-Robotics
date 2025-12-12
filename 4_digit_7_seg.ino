// Segment pins (a to g, then dp)
int segpin[7] = {13, 7, 9, 10, 11, 12, 0 };

// Digit control pins
 int dpin[4] = {3, 4, 5, 6};

// Digit to 7-segment encoding (0-9)
//         a  b  c  d  e  f  g  dp
 const int arr[10][7] = {
  {1, 1, 1, 1, 1, 1, 0 }, // 0
  {0, 1, 1, 0, 0, 0, 0 }, // 1
  {1, 1, 0, 1, 1, 0, 1 }, // 2
  {1, 1, 1, 1, 0, 0, 1 }, // 3
  {0, 1, 1, 0, 0, 1, 1 }, // 4
  {1, 0, 1, 1, 0, 1, 1 }, // 5
  {1, 0, 1, 1, 1, 1, 1 }, // 6
  {1, 1, 1, 0, 0, 0, 0 }, // 7
  {1, 1, 1, 1, 1, 1, 1 }, // 8
  {1, 1, 1, 1, 0, 1, 1 }  // 9
  };

int timer=100;


void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 7; i++) {
    pinMode(segpin[i], OUTPUT);
  }
  for (int j = 0; j < 4; j++) {
    pinMode(dpin[j], OUTPUT);
  }
}

void loop() {
  Serial.print("Enter number to be displayed:");

  while(Serial.available()== 0) {}

  int num = (Serial.parseInt());
  Serial.println(num);

  int d0 = num %10 ;
  int d1 = (num % 100) / 10;
  int d2 = (num % 1000) / 10;
  int d3 = num /1000;
  
  for (int k = 0; k < timer; k++) {
   digitalWrite(dpin[0], LOW);
   digitalWrite(dpin[1], HIGH);
   digitalWrite(dpin[2], HIGH);
   digitalWrite(dpin[3], HIGH);
  

 for (int i = 0; i < 7; i++) {
   digitalWrite(segpin[i], arr[d3][i]);}
   delay(5);
    
   digitalWrite(dpin[0], HIGH);
   digitalWrite(dpin[1], LOW);
   digitalWrite(dpin[2], HIGH);
   digitalWrite(dpin[3], HIGH);
  
  for (int i = 0; i < 7; i++) {
   digitalWrite(segpin[i], arr[d2][i]);}
   delay(5);
    
   digitalWrite(dpin[0], HIGH);
   digitalWrite(dpin[1], HIGH);
   digitalWrite(dpin[2], LOW);
   digitalWrite(dpin[3], HIGH); 

  for (int i = 0; i < 7; i++) {
   digitalWrite(segpin[i], arr[d1][i]);}
   delay(5);
    
   digitalWrite(dpin[0], HIGH);
   digitalWrite(dpin[1], HIGH);
   digitalWrite(dpin[2], HIGH);
   digitalWrite(dpin[3], LOW);

   for (int i = 0; i < 7; i++) {
   digitalWrite(segpin[i], arr[d0][i]);}
   delay(5);
  }
  for (int j = 0; j < 4; j++) {
   digitalWrite(dpin[j],HIGH);}
}
    
