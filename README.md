# Funkmodul – Drahtlose Kommunikation mit nRF24L01

## Übersicht

Dieses Projekt ermöglicht eine drahtlose Kommunikation zwischen zwei Mikrocontrollern mithilfe des **nRF24L01+ Funkmoduls** im 2,4-GHz-Bereich.

Das Ziel des Projekts ist eine einfache, zuverlässige und energieeffiziente Übertragung kleiner Datenmengen, beispielsweise Zustände, Steuerbefehle oder Sensordaten.

Das nRF24L01+ arbeitet als Transceiver und kann sowohl Daten senden als auch empfangen. Die Kommunikation erfolgt über die SPI-Schnittstelle des Mikrocontrollers. Die verwendete RF24-Bibliothek stellt eine einfache Schnittstelle zur Konfiguration und Nutzung des Funkmoduls bereit. :contentReference[oaicite:0]{index=0}

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
