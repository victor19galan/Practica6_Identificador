#include <Arduino.h>
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 5
#define RST_PIN 22

MFRC522 rfid(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(115200);
  delay(1000);

  SPI.begin(18, 19, 23, SS_PIN);
  rfid.PCD_Init();

  Serial.println("Iniciando RC522...");

  byte version = rfid.PCD_ReadRegister(rfid.VersionReg);
  Serial.print("Version RC522: 0x");
  Serial.println(version, HEX);

  if (version == 0x00 || version == 0xFF) {
    Serial.println("ERROR: No hay comunicacion con el RC522. Revisa cables/alimentacion.");
  } else {
    Serial.println("RC522 detectado. Acerca tarjeta...");
  }
}

void loop() {
  if (!rfid.PICC_IsNewCardPresent()) return;
  if (!rfid.PICC_ReadCardSerial()) return;

  Serial.print("UID: ");
  for (byte i = 0; i < rfid.uid.size; i++) {
    Serial.print(rfid.uid.uidByte[i], HEX);
    Serial.print(" ");
  }
  Serial.println();

  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
}