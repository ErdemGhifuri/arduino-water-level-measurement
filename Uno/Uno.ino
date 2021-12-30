#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 // attach pin D3 Arduino to pin Trig of HC-SR04
#define powerPin 13 // use pin D13 to power HC-SR04 VCC pin

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

void setup() {
  pinMode(powerPin, OUTPUT); // Sets the powerPin as an OUTPUT
  digitalWrite(powerPin, HIGH); // Activate powerPin
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // Serial Communication is starting with 9600 of baudrate speed
}

void loop() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delay(1000);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delay(1000);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor & send data to NodeMCU in serial way
  Serial.println(distance);
  delay(5000);
}
