#ifndef PACIENTE_H
#define PACIENTE_H

#include <Arduino.h>
#include "Examen.h"

class Paciente {
    public:
        Paciente();
        
        void setNombre(String n);
        void setApellido(String a);
        void setEdad(int ed);
        void setSexo(char s);
        void setDomicilio(String d);
        void setTelefono(String t);
        void setContactoEmerg(String CE);
        void setExamen(Examen ex);

        String getNombre();
        String getApellido();
        int getEdad();
        char getSexo();
        String getDomicilio();
        String getTelefono();
        String getContactoEmerg();

        Examen & getExamen();

    


    private:
        String nombre;
        String apellido;
        int edad;
        char sexo;
        String domicilio;
        String telefono;
        String contactoEmerg;
        
        Examen examen;
        
};

#endif
