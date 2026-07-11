#include <SPI.h>
#include <RF24.h>

#define CE 9
#define CSN 10

RF24 funk(CE, CSN);
const byte adresse[6] = "TEST2";

void setup() {
  Serial.begin(9600);

  if (!funk.begin()) {
    Serial.println("Funkmodul NICHT gefunden!");
    while (1);
  }

  funk.openWritingPipe(adresse);
  // funk.openReadingPipe(1, adresse);
  funk.setPALevel(RF24_PA_LOW);
  funk.stopListening(); 
  // funk.startListening();

  Serial.println("Empfänger bereit");
}
void loop() {
  uint8_t wert = 42;

  bool erfolg = funk.write(&wert, sizeof(wert));

  if (erfolg) {
    Serial.print("Gesendet: ");
    Serial.println(wert);
  } else {
    Serial.println("Senden fehlgeschlagen");
  }

  delay(1000);
}
/*
void loop() {
  if (funk.available()) {
    Serial.println("DATA!");

    uint8_t wert;
    funk.read(&wert, sizeof(wert));
    if (wert != 216 && wert != 0) {
      Serial.print("Empfangen: ");
      Serial.println(wert);
    }


  } else {
    Serial.println("nichts...");
    delay(500);
  }
}

void setup() {
  Serial.begin(9600);
  while (!Serial) {;}
  Serial.println("Gestartet!");
  pinMode(3, OUTPUT);
  if (!funk.begin()) {
    Serial.println("Funkmodul NICHT gefunden!");
    digitalWrite(3, HIGH);
  }
  else {
    Serial.println("Gefunden!");
  }
}
void loop() {
}*/