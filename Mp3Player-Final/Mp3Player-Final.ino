#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

// Use pins 2 and 3 to communicate with DFPlayer Mini
static const uint8_t PIN_MP3_TX = 2; // Connects to module's RX 
static const uint8_t PIN_MP3_RX = 3; // Connects to module's TX 
SoftwareSerial softwareSerial(PIN_MP3_RX, PIN_MP3_TX);

const int leiserPin = 7;
const int lauterPin = 8;
const int weiterPin = 6;
const int zurueckPin = 5;
const int pausePin = 9;

// Create the Player object
DFRobotDFPlayerMini player;

bool paused = false;

void setup() {

  pinMode(leiserPin, INPUT_PULLUP);
  pinMode(lauterPin, INPUT_PULLUP);
  pinMode(weiterPin, INPUT_PULLUP);
  pinMode(zurueckPin, INPUT_PULLUP);
  pinMode(pausePin, INPUT_PULLUP);

  // Init USB serial port for debugging
  Serial.begin(9600);
  // Init serial port for DFPlayer Mini
  softwareSerial.begin(9600);

  // Start communication with DFPlayer Mini
  if (player.begin(softwareSerial)) {
    Serial.println("OK");

    // Set volume to maximum (0 to 30).
    player.volume(30);
    // Play the first MP3 file on the SD card
    player.play(1);
  } else {
    Serial.println("Connecting to DFPlayer Mini failed!");
  }
}

void loop() {

  if (digitalRead(leiserPin) == HIGH) {
    player.volumeDown();
    delay(200);
  }
  
  if (digitalRead(lauterPin) == HIGH) {
    player.volumeUp();
    delay(200);
  }

  if (digitalRead(weiterPin) == HIGH) {
    player.next();
    delay(200);
  }
  
  if (digitalRead(zurueckPin) == HIGH) {
    player.previous();
    delay(200);
  }

  if (digitalRead(pausePin) == HIGH) {
    delay(100);
    if (digitalRead(pausePin) == HIGH) {
      if (paused) {
        player.start();
        paused = false;
      } else {
        player.pause();
        paused = true;
      }
      delay(200);
    }
  }
}
