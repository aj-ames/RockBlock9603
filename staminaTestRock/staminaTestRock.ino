#include <IridiumSBD.h>
#include <SoftwareSerial.h>

SoftwareSerial nss(8, 9);
IridiumSBD isbd(nss, 15);
static const int ledPin = 13;

void setup() {
  int signalQuality = -1;
  pinMode(ledPin, OUTPUT);

  Serial.begin(115200);
  nss.begin(19200);

  isbd.attachConsole(Serial);
  isbd.setPowerProfile(0);
  isbd.setMinimumSignalQuality(1);
  isbd.begin();

  while(true) {
    isbd.getSignalQuality(signalQuality);
    delay(5000);
  }
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(100);
  digitalWrite(ledPin, LOW);
  delay(100);
}

bool ISBDCallback()
{
   digitalWrite(ledPin, (millis() / 1000) % 2 == 1 ? HIGH : LOW);
   return true;
}
