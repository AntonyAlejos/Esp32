#ifndef PACIENTE_H
#define PACIENTE_H

#include <Arduino.h>
#include "Examen.h"

class Paciente {
    public:
        Paciente();

        String getNombre();
        String getApellido();
        int getID();
        Examen & getExamen();

        void setNombre(String n);
        void setApellido(String a);
        void setID(int i);




    private:
        String nombre;
        String apellido;
        int id;
        Examen examen;
        
};

#endif
