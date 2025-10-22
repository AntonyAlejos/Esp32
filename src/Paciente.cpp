#include "Paciente.h"
//Constructor
Paciente::Paciente() {
    nombre = "";
    apellido = "";
    id = 0;
}

//geters

String Paciente::getNombre(){return nombre;}
String Paciente::getApellido(){return apellido;}
int Paciente::getID(){return id;}
Examen & Paciente::getExamen(){return examen;}

//Seters

void Paciente::setNombre(String n){nombre=n;}
void Paciente::setApellido(String a){apellido=a;}
void Paciente::setID(int i){id=i;}