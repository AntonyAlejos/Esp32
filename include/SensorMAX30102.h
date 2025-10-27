#ifndef SENSOR_MAX30102_H
#define SENSOR_MAX30102_H

#include <Arduino.h>
#include <Wire.h>
#include "MAX30105.h"
#include "spo2_algorithm.h"

class SensorMAX30102 {
private:
    MAX30105 sensor;
    static const int bufferLength = 100;
    uint32_t irBuffer[bufferLength];
    uint32_t redBuffer[bufferLength];
    int32_t SpO2;
    int32_t heartRate;
    int8_t validSpO2;
    int8_t validHeartRate;
    
public:
    bool iniciar();       // Inicializa el sensor
    bool actualizar();    // Lee una vez los datos y calcula HR/SpO2 (true si ok)
    int getPulso();       // Devuelve último pulso leído
    int getOxigeno();     // Devuelve último nivel de oxígeno leído
};

#endif
