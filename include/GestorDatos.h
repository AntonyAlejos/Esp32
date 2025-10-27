#ifndef GESTORDATOS_H
#define GESTORDATOS_H

#include <Arduino.h>
#include "Paciente.h"
#include "FichaMedica.h"

class GestorDatos {
public:
    GestorDatos(FichaMedica&);

    bool recibirDesdeSerial(String &linea);
    void guardarEnSD(Paciente &paciente);
    String enviarATelegram(Paciente &paciente);
    Paciente parsearDesdeCSV(const String& linea);
private:
    FichaMedica & ficha;
};

#endif
