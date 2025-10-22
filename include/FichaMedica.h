#ifndef FICHAMEDICA_H
#define FICHAMEDICA_H

#include <Arduino.h>
#include "Paciente.h"


class FichaMedica{
    public:
        FichaMedica();
        String  generarFicha(Paciente& paciente);
        void limpiarFichaMedica();
    
    private:
        
};
#endif