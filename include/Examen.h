
#ifndef EXAMEN_H
#define EXAMEN_H

#include <Arduino.h>
class Examen{
    public:
        Examen();
        //metodos para calcular diferentes valores medicos.
        //metodos para limpiar. 
        void setTemperatura(float temp);
        void setFrecuencia(int frc);
        void setSpo2(int SPO2);
        void setFecha(String fech);
        void setPresion(int press);

        float getTemperatura();
        int getFrecuenciaCardiaca();
        int getSpo2();
        String getFecha();
        int getPresion();
    private:
        float temperatura;
        int frecuenciaCardiaca;
        int spo2;
        String fecha;
        int presion;

};
#endif