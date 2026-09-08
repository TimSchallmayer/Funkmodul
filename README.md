# Funkmodul – Drahtlose Kommunikation mit nRF24L01

## Übersicht

Dieses Projekt ermöglicht eine drahtlose Kommunikation zwischen zwei Mikrocontrollern mithilfe des **nRF24L01+ Funkmoduls** im 2,4-GHz-Bereich.

Das Ziel des Projekts ist eine einfache, zuverlässige und energieeffiziente Übertragung kleiner Datenmengen, beispielsweise Zustände, Steuerbefehle oder Sensordaten.

Das nRF24L01+ arbeitet als Transceiver und kann sowohl Daten senden als auch empfangen. Die Kommunikation erfolgt über die SPI-Schnittstelle des Mikrocontrollers. Die verwendete RF24-Bibliothek stellt eine einfache Schnittstelle zur Konfiguration und Nutzung des Funkmoduls bereit. :contentReference[oaicite:0]{index=0}

---

# Bilder
<img width="808" height="851" alt="image" src="https://github.com/user-attachments/assets/ca0e71a7-d795-4e39-8eb4-5a8cddd1250c" />
~Platinenentwurf
<img width="1080" height="1920" alt="platine" src="https://github.com/user-attachments/assets/2ea999ed-bb15-45c7-a8a1-c8e7c56442ad" />
~Funkmodul
<img width="2048" height="1277" alt="schaltplan" src="https://github.com/user-attachments/assets/45fb0b5c-e28e-41d9-b74f-5b78ef2d5d79" />
~Schaltplan bzw. erster Entwurf

---

# Funktionen

- Drahtlose Datenübertragung über 2,4 GHz
- Kommunikation zwischen mehreren Mikrocontrollern möglich
- Einstellbare:
  - Sendeleistung
  - Datenrate
  - Funkkanal
- Geringer Energieverbrauch
- Geeignet für Batterieanwendungen

---

# Hardware

## Benötigte Komponenten

| Bauteil | Anzahl |
|---|---:|
| Mikrocontroller (z.B. Arduino / ATmega32U4) | 2 |
| nRF24L01+ Funkmodul | 2 |
| Kondensator 10–100 µF | 2 |
| Verbindungskabel | nach Bedarf |

Das nRF24L01+ nutzt das 2,4-GHz-ISM-Band und kommuniziert über SPI. Es besitzt je nach Variante eine integrierte PCB-Antenne oder eine externe Antenne. :contentReference[oaicite:1]{index=1}

---

# Verdrahtung

## nRF24L01+ → Mikrocontroller

| nRF24L01 | Funktion |
|---|---|
| VCC | 3,3 V Versorgung |
| GND | Masse |
| CE | Chip Enable |
| CSN | Chip Select |
| SCK | SPI Clock |
| MOSI | SPI Daten Eingang |
| MISO | SPI Daten Ausgang |

⚠️ Wichtig:
Das Funkmodul darf **nicht mit 5 V versorgt werden**.

Empfohlen:
- 3,3-V-Versorgung verwenden
- Kondensator zwischen VCC und GND direkt am Funkmodul einsetzen

---

# Software

## Benötigte Bibliotheken

Installiere die RF24-Bibliothek:
