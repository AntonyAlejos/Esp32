
#ifndef EXAMEN_H
#define EXAMEN_H

#include <Arduino.h>
class Examen{
    public:
        Examen();
        //metodos para calcular diferentes valores medicos.
        //metodos para limpiar. 
        void setFecha(String fech);
        void setOxigeno(float ox);
        void setPulso(float pul);
        void setTemperatura(float temp);
        void setPresionS(float pressS);
        void setPresionD(float pressD);
        void setDiagnostico(String d);

        String getFecha();
        float getOxigeno();
        float getPulso();
        float getTemperatura();
        float getPresionS();
        float getPresionD();
        String getdiagnostico();
    private:
        String fecha;
        float oxigeno;
        float pulso;
        float temperatura;
        float pSistolica;
        float pDiastolica;
        String diagnostico;
        
};
#endif