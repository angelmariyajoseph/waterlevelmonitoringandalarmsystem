#define TRIG_PIN 25
#define ECHO_PIN 26
#define buzzer 21

long duration;
float distance;

void setup() {
  Serial.begin(115200);
  
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(buzzer, OUTPUT);

  digitalWrite(buzzer, LOW);  // Start with relay OFF
}

void loop() {

  // Send trigger pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(TRIG_PIN, LOW);

  // Read echo time
  duration = pulseIn(ECHO_PIN, HIGH);

  // Calculate distance
  distance = duration * 0.0343 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Relay Control Logic

   if (distance > 4) {
    digitalWrite(buzzer, HIGH);  // ON
    Serial.println("motor low");
  }else {
    digitalWrite(buzzer, LOW);  // ON
  } 

  delay(500);
}