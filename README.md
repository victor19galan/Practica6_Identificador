📡 README – Identificación de tarjetas RFID/NFC
🧠 Descripción

Este proyecto permite identificar tarjetas RFID/NFC utilizando un módulo RC522 y una ESP32, mostrando por el monitor serie el UID y el tipo de tarjeta detectada.

🔧 Funcionalidad
Detección de tarjeta NFC
Lectura del UID
Identificación del tipo de tarjeta

Ejemplo:

UID: 13 B9 D6 06
Tipo: MIFARE 1K
🔍 Tipos detectados
✔ MIFARE Classic → lectura/escritura posible
❌ ISO/IEC 14443-4 → solo detección (ej. tarjetas bancarias)
🔌 Hardware
ESP32
RC522
Tarjetas NFC
🚀 Uso
Subir el código
Abrir monitor serie (115200)
Acercar tarjeta
Ver UID y tipo
