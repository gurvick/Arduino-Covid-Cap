
const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 11;
const int ledPin = 13;

long duration;
int distance;
int safetyDistance;

void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(buzzer, OUTPUT);
pinMode(ledPin, OUTPUT);
Serial.begin(9600); // Starts the serial communication
}


void loop() {
// Clears trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets trigPin on high for 10 micro sec
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns travel time
duration = pulseIn(echoPin, HIGH);

// Distance
distance= duration*0.034/2;

safetyDistance = distance;
if (safetyDistance <= 40
){ // Enter the Distance
  digitalWrite(buzzer, HIGH);
  digitalWrite(ledPin, HIGH);
}
else{
  digitalWrite(buzzer, LOW);
  digitalWrite(ledPin, LOW);
}

Serial.print("Distance: ");
Serial.println(distance);
}
