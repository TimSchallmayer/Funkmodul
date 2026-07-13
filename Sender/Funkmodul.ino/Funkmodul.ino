#include <SPI.h>
#include <RF24.h>
#define CE 9
#define CSN 10
#define LED 3
#define motor 5
#define button_1 6
#define button_2 8
#define button_3 7

RF24 funk(CE, CSN);
const byte adresse_epmfangen[6] = "GeraetA";  //Adresse des Geräts
const byte adresse_senden[6] = "GeraetB";     //Adresse wohin gesendet werden soll, also die des anderen Geräts
void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(motor, OUTPUT);
  pinMode(button_1, INPUT_PULLUP);
  pinMode(button_2, INPUT_PULLUP);
  pinMode(button_3, INPUT_PULLUP);
  if (!funk.begin()) {
    Serial.println("Funkmodul NICHT gefunden!");
    while (true) {
      digitalWrite(LED, HIGH);
      delay(100);
      digitalWrite(LED, LOW);
    }
  }
  funk.openReadingPipe(1, adresse_epmfangen);
  funk.openWritingPipe(adresse_senden);
  funk.setPALevel(RF24_PA_LOW);
  funk.startListening();


  Serial.println("Empfänger bereit");
}
uint8_t set_wert() {
  if (digitalRead(button_1) == LOW) return 1;
  if (digitalRead(button_2) == LOW) return 2;
  if (digitalRead(button_3) == LOW) return 3;
  else return 0;
}
void loop() {
  if (funk.available() && digitalRead(button_1) != LOW && digitalRead(button_2) != LOW && digitalRead(button_3) != LOW) {
    digitalWrite(LED, HIGH);
    uint8_t wert;
    funk.read(&wert, sizeof(wert));
    if (wert == 1 || wert == 2 || wert == 3) {
      Serial.print("Empfangen: ");
      Serial.println(wert);
      switch (wert) {
        case 1: 
          analogWrite(motor, 85);
          break;
        case 2:
          analogWrite(motor, 170);
          break;
        case 3:
          analogWrite(motor, 255);
          break;
        default:
          break;
      }
      digitalWrite(LED, LOW);
      delay(100);
      digitalWrite(LED, HIGH);
      delay(400);
      analogWrite(motor, 0);
    }
    digitalWrite(LED, LOW);
  }
  else if (digitalRead(button_1) == LOW || digitalRead(button_2) == LOW || digitalRead(button_3) == LOW) {
    funk.stopListening();
    uint8_t wert = set_wert();
    if (wert == 0) {
      Serial.println("Input Nicht richtig empfangen.");
    }
    digitalWrite(LED, HIGH);
    bool erfolg = funk.write(&wert, sizeof(wert));

    if (erfolg) {
      Serial.print("Gesendet: ");
      Serial.println(wert);
    } else {
      Serial.println("Senden fehlgeschlagen");
    }
    while (digitalRead(button_1) == LOW ||
           digitalRead(button_2) == LOW ||
           digitalRead(button_3) == LOW)          
      {
      delay(10);
      }
    digitalWrite(LED, LOW);
    funk.startListening();
  }
}
