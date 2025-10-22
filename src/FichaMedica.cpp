
#include"FichaMedica.h"

//FichaMedica::FichaMedica(String n,String a,String id):nombre(n),apellido(a),idPaciente(id){}
FichaMedica::FichaMedica(){}


String FichaMedica::generarFicha(Paciente& paciente){
    
    String ficha = "    🩺FICHA MÉDICA ELECTRONICA🩺    \n";
    
    ficha +="-------------------------------------------------------------------------\n";
    ficha += "👤Paciente: " + paciente.getNombre() + " " + paciente.getApellido() + " (ID: "+paciente.getID()+")\n"; 
    ficha += "📅Fecha: " + paciente.getExamen().getFecha() + "\n\n";

    ficha +="🌡️Temperatura Corporal: " +String(paciente.getExamen().getTemperatura()) + "°C\n";
    ficha +="🫀Frecuencia Cardíaca: " + String(paciente.getExamen().getFrecuenciaCardiaca())+ "\n";
    ficha +="🫁 Saturación de oxígeno: " + String(paciente.getExamen().getSpo2()) + " %SpO2\n";
    ficha +="🩸 Presión arterial: " + String(paciente.getExamen().getPresion()) + " mmHg\n";

    ficha +="\nObservaciones: \n";
    
    return ficha;

}