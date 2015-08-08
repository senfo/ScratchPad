/*
    A really simple project, which demonstrates how you could use the Ardunio to build something similar to the
    reverse sensor on a vehicle.
*/

const unsigned short TRIG = 4;
const unsigned short ECHO = 5;
const unsigned short BUZZER = 13;

long duration;
long distance;

void setup() {
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(TRIG, LOW);
  duration = pulseIn(ECHO, HIGH);
  distance = durationToInches(duration);
  
  if (distance > 9) {
    noTone(BUZZER);
  }
  else if (distance <= 9 && distance > 6) {
    tone(BUZZER, 1000, 100);
  }
  else if (distance <= 6 && distance > 3) {
    tone(BUZZER, 1000, 50);
  }
  else if (distance <= 3) {
    tone(BUZZER, 1000);
  }
  
  Serial.println(distance);
  
  delay(100);
}

long durationToInches(long duration) {
  return duration / 73.746 / 2;
}

long durationToCm(long duration) {
  return duration / 58.2;
}
