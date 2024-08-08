// Libary
#include <NewPing.h>
#include <Servo.h>

//Constants
#define button 2
#define trig_pin 9
#define echo_pin 10
int degree = 0;
#define max_distance 400
float duration, distance;

//Create Servo Engine
Servo engine;

NewPing sonar(trig_pin, echo_pin, max_distance);

void setup() {
  Serial.begin(9600);
  engine.attach(3);
  pinMode(button, INPUT);
}

void loop() {
  distance = sonar.ping_cm();
  Serial.println(distance);

  if (distance == 10.00 || digitalRead(button) == 1) {
    Serial.println("Tıklandı");
    engine.write(90);
    delay(2000);
  } else {
    engine.write(0);
  }
}
