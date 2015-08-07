/* Sequences a series of LEDs on/off using a shift register */

#define BITS 255
#define SEED 128
#define CLOCK_PIN 3
#define DATA_PIN 2
#define LATCH_PIN 4

int value = BITS;
int seed = SEED;
int sensorValue = 0;

void setup() {
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
}

void loop() {
  sensorValue = analogRead(A0);
  
  // Take the latch pin low so the LEDs don't change while sending the bits
  digitalWrite(LATCH_PIN, LOW);
  
  // Shift out the bits
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, value);
  
  // Take the latch pin high to turn LEDS on
  digitalWrite(LATCH_PIN, HIGH); 
  
  // Figure out the next sequence
  seed = seed == 1 ? SEED : seed / 2;
  value = BITS ^ seed;
    
  delay(sensorValue);
}
