#include "SensorMAX30102.h"

bool SensorMAX30102::iniciar() {
    if (!sensor.begin(Wire, I2C_SPEED_STANDARD)) {
        Serial.println("❌ Error: no se detectó el MAX30102");
        return false;
    }

    // Configuración básica
    sensor.setup();
    sensor.setPulseAmplitudeRed(0x0A);
    sensor.setPulseAmplitudeIR(0x0A);
    sensor.setPulseAmplitudeGreen(0); // apagamos LED verde si no se usa

    Serial.println("✅ MAX30102 iniciado correctamente");
    return true;
}

bool SensorMAX30102::actualizar() {
    // Recolecta muestras (máximo 2 segundos de espera)
    for (byte i = 0; i < bufferLength; i++) {
        unsigned long start = millis();
        while (!sensor.check()) {
            if (millis() - start > 2000) { // timeout 2 s
                Serial.println("⚠️ Timeout al leer el sensor");
                return false;
            }
        }

        redBuffer[i] = sensor.getRed();
        irBuffer[i] = sensor.getIR();
    }

    // Ejecuta el algoritmo de cálculo
    maxim_heart_rate_and_oxygen_saturation(
        irBuffer, bufferLength, redBuffer,
        &SpO2, &validSpO2, &heartRate, &validHeartRate);

    return true;
}

int SensorMAX30102::getPulso() {
    actualizar();
    return validHeartRate ? heartRate : -1;
}

int SensorMAX30102::getOxigeno() {
    actualizar();
    return validSpO2 ? SpO2 : -1;
}
