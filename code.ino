#define TRIG_PIN 9  // Trigger pin of ultrasonic sensor
#define ECHO_PIN 10 // Echo pin of ultrasonic sensor
#define RELAY_PIN 8 // Relay pin

void setup() {
  pinMode(TRIG_PIN, OUTPUT);  // Set trigger pin as output
  pinMode(ECHO_PIN, INPUT);   // Set echo pin as input
  pinMode(RELAY_PIN, OUTPUT); // Set relay pin as output
  digitalWrite(RELAY_PIN, LOW); // Initialize relay to OFF
  
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  // Send a 10-microsecond pulse to trigger pin
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  // Read the time for the echo
  long duration = pulseIn(ECHO_PIN, HIGH);
  
  // Calculate the distance in centimeters
  float distance = (duration * 0.034) / 2;
  
  // Print distance to Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Check distance and control relay
  if (distance <= 10) { // If an object is within 10 cm
    digitalWrite(RELAY_PIN, HIGH); // Turn ON the relay
  } else {
    digitalWrite(RELAY_PIN, LOW); // Turn OFF the relay
  }
  
  delay(100); // Small delay
}