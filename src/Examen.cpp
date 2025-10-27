#include "Examen.h"

Examen::Examen() {}

void Examen::setFecha(String fech){fecha=fech;}
void Examen::setOxigeno(float ox ) {oxigeno = ox;}
void Examen::setPulso(float pul){pulso=pul;}
void Examen::setTemperatura(float temp){temperatura=temp;}
void Examen::setPresionS(float pressS){pSistolica=pressS;}
void Examen::setPresionD(float pressD){pDiastolica=pressD;}
void Examen::setDiagnostico(String d){diagnostico=d;}


String Examen::getFecha(){return fecha;}
float Examen::getOxigeno(){return oxigeno;}
float Examen::getPulso(){return pulso;}
float Examen::getTemperatura(){return temperatura;}
float Examen::getPresionS(){return pSistolica;}
float Examen::getPresionD(){return pDiastolica;}
String Examen::getdiagnostico(){return diagnostico;}