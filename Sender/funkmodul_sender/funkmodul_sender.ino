#include <SPI.h>
#include <RF24.h>

#define CE 9
#define CSN 10

RF24 funk(CE, CSN);
const byte adresse_epmfangen[6] = "GeraetB"; //Adresse des Geräts 
const byte adresse_senden[6] = "GeraetA"; //Adresse wohin gesendet werden soll, also die des anderen Geräts

void setup() {
  Serial.begin(9600);
  if (!funk.begin()) {
    Serial.println("Funkmodul NICHT gefunden!");
    
  }

  funk.openWritingPipe(adresse);
  funk.setPALevel(RF24_PA_LOW);
  funk.stopListening(); 


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
