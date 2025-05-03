#include <SoftwareSerial.h>

#define LED_PIN 2
#define CHARGE_PIN 3

SoftwareSerial BT(10, 11); // RX, TX for Bluetooth module

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(CHARGE_PIN, OUTPUT);
  BT.begin(9600);
}
void loop() {
  if (BT.available()) {
      char cmd = BT.read();
    switch (cmd) {
      case '1': // Turn LED ON
        digitalWrite(LED_PIN, HIGH);
        break;
      case '0': // Turn LED OFF
        digitalWrite(LED_PIN, LOW);
        break;
      case 'C': // Start charging
        digitalWrite(CHARGE_PIN, HIGH);
        break;
      case 'S': // Stop charging
        digitalWrite(CHARGE_PIN, LOW);
        break;
    }
  }
}