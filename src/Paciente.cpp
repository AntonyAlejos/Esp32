#include "Paciente.h"
//Constructor
Paciente::Paciente() {}

//geters

String Paciente::getNombre(){return nombre;}
String Paciente::getApellido(){return apellido;}
int Paciente::getEdad(){return edad;}
char Paciente::getSexo(){return sexo;}
String Paciente::getDomicilio(){return domicilio;}
String Paciente::getTelefono(){return telefono;}
String Paciente::getContactoEmerg(){return contactoEmerg;}
Examen& Paciente::getExamen(){return examen;}
//Seters
void Paciente::setNombre(String n){nombre=n;}
void Paciente::setApellido(String a){apellido=a;}
void Paciente::setEdad(int ed){edad=ed;}
void Paciente::setSexo(char s){sexo=s;}
void Paciente::setDomicilio(String d){domicilio=d;}
void Paciente::setTelefono(String t){telefono=t;}
void Paciente::setContactoEmerg(String CE){contactoEmerg=CE;}
void Paciente::setExamen(Examen ex){examen=ex;}