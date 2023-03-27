#include <Servo.h>

const int TASTER1_PIN = 2;
const int TASTER2_PIN = 3;
const int SERVO_PIN = 9;

Servo servo;

void setup() {
  Serial.begin(9600);

  pinMode(TASTER1_PIN, INPUT);
  pinMode(TASTER2_PIN, INPUT);

  servo.attach(SERVO_PIN);
}

void loop() {
  if (digitalRead(TASTER1_PIN) == HIGH) {
    Serial.println("Taster 1 gedrückt - Servo fährt vorwärts");
    servo.write(180);
    delay(1000);
    servo.write(90);
    Serial.println("Servo fährt zu Ausgangsposition");
  }

  if (digitalRead(TASTER2_PIN) == HIGH) {
    Serial.println("Taster 2 gedrückt - Servo fährt rückwärts");
    servo.write(0);
    delay(1000);
    servo.write(90);
    Serial.println("Servo fährt zu Ausgangsposition");
  }
}
