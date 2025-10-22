#include "Examen.h"

Examen::Examen() {
    temperatura = 0.0;
    frecuenciaCardiaca = 0;
    spo2 = 0;
    fecha = "";
    presion=0;
}

float Examen::getTemperatura() {
    return temperatura;
}

int Examen::getFrecuenciaCardiaca() {
    return frecuenciaCardiaca;
}

int Examen::getSpo2() {
    return spo2;
}
String Examen::getFecha() {
    return fecha;
}
int Examen::getPresion(){
    return presion;}

void Examen::setTemperatura(float temp) {
    temperatura = temp;
}

void Examen::setFrecuencia(int f) {
    frecuenciaCardiaca = f;
}

void Examen::setSpo2(int s) {
    spo2 = s;
}

void Examen::setFecha(String f) {
    fecha = f;}
    
void Examen::setPresion(int p) {
    presion = p;
}


