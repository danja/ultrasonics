#include <Arduino.h>
//#include <cmath>
// ---------------------------------------------------------------- //
// Thereminimal v0.1
// Using Arduino & Ultrasonic Sensor Module HC-SR04
//
// Danny Ayers 2020
// Sections derived from code of Arbi Abdul Jabbaar
// ---------------------------------------------------------------- //

const int ECHO_PIN = 2; // attach pin D2 Arduino to pin Echo of HC-SR04
const int TRIG_PIN = 3; //attach pin D3 Arduino to pin Trig of HC-SR04
const int TONE_PIN = 4;

const int C = 343;                // speed of sound in m/s
const int DISTANCE_SCALE = 20000; // factor to get distance in cm
const int FREQ_SCALE = 30;        // factor to produce a reasonable pitch

// defines variables
long duration; // variable for the duration of sound wave travel
int distance;  // variable for the distance measurement

void setup()
{
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  // Zeros trig pin
  digitalWrite(TRIG_PIN, LOW);

  Serial.begin(9600);
  Serial.println("Thereminimal");
}

void loop()
{
  // ping the module
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // sound travel time in microseconds
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * C / DISTANCE_SCALE; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor

  Serial.print(distance);
  Serial.println(" cm");

  int freq = distance * FREQ_SCALE;

  if (distance < 200) // only play if distance < 200cm
  {
    tone(TONE_PIN, freq);
    // Serial.print(freq);
    // Serial.println(" Hz");
  }
  else
  {
    noTone(TONE_PIN);
  }
  // delay(200);
}