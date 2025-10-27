
#include"FichaMedica.h"

//FichaMedica::FichaMedica(String n,String a,String id):nombre(n),apellido(a),idPaciente(id){}
FichaMedica::FichaMedica(){}


String FichaMedica::generarFicha(Paciente& paciente){
    
    /*String ficha = "    🩺FICHA MÉDICA ELECTRONICA🩺    \n";
    
    ficha +="-------------------------------------------------------------------------\n";
    ficha += "👤Paciente: " + paciente.getNombre() + " " + paciente.getApellido() + " (ID: "+String(paciente.getID())+")\n"; 
    ficha += "📅Fecha: " + paciente.getExamen().getFecha() + "\n\n";

    ficha +="🌡️Temperatura Corporal: " +String(paciente.getExamen().getTemperatura()) + "°C\n";
    ficha +="🫀Frecuencia Cardíaca: " + String(paciente.getExamen().getFrecuenciaCardiaca())+ "\n";
    ficha +="🫁 Saturación de oxígeno: " + String(paciente.getExamen().getSpo2()) + " %SpO2\n";
    ficha +="🩸 Presión arterial: " + String(paciente.getExamen().getPresion()) + " mmHg\n";

    ficha +="\nObservaciones: \n";*/

    Examen ex = paciente.getExamen();

    String ficha = "    🩺 FICHA MÉDICA ELECTRÓNICA 🩺    \n";
    ficha += "-------------------------------------------------------------\n";

    // 🧍 Datos personales
    ficha += "👤 Nombre: " + paciente.getNombre() + " " + paciente.getApellido() + "\n";
    ficha += "📆 Edad: " + String(paciente.getEdad()) + " años\n";
    ficha += "⚧ Sexo: " + String(paciente.getSexo()) + "\n";
    ficha += "🏠 Domicilio: " + paciente.getDomicilio() + "\n";
    ficha += "📞 Teléfono: " + paciente.getTelefono() + "\n";
    ficha += "🆘 Contacto de emergencia: " + paciente.getContactoEmerg() + "\n";
    ficha += "📅 Fecha del examen: " + ex.getFecha() + "\n\n";

    // 🩺 Datos clínicos (usando los nuevos atributos)
    ficha += "🫁 Oxígeno: " + String(ex.getOxigeno(), 1) + " %SpO₂\n";
    ficha += "🫀 Pulso: " + String(ex.getPulso(), 0) + " lpm\n";
    ficha += "🌡️ Temperatura: " + String(ex.getTemperatura(), 1) + " °C\n";
    ficha += "🩸 Presión arterial: " + String(ex.getPresionS(), 0) + "/" + String(ex.getPresionD(), 0) + " mmHg\n\n";

    ficha += "🧾 Observaciones:\n";

    // === Diagnóstico automático === // Ejemplo: "1001n"
    String observaciones = "";

    if (ex.getOxigeno()<95) observaciones += "⚠️ Oxígeno bajo\n";
    else if (ex.getOxigeno()>100) observaciones += "⚠️ Oxígeno Anormalmente alto\n";
    
    if (ex.getPulso()<60) observaciones += "⚠️ Pulso bajo (bradicardia)\n";
    else if (ex.getPulso()>100) observaciones += "⚠️ Pulso alto (taquicardia)\n";
    
    if (ex.getTemperatura()<35.5) observaciones += "⚠️ Temperatura baja (hipotermia)\n";
    else if (ex.getTemperatura()>38) observaciones += "⚠️ Temperatura alta (fiebre)\n";

    if (ex.getPresionS()<90) observaciones += "⚠️ Presión sistólica baja (hipotensión)\n";
    else if (ex.getPresionS()>120) observaciones += "⚠️ Presión sistólica alta (hipertensión)\n";
    
    if (ex.getPresionD()<60) observaciones += "⚠️ Presión diastólica baja (hipotensión)\n";
    else if (ex.getPresionD()>80) observaciones += "⚠️ Presión diastólica alta(hipertensión)\n";
    

    if (observaciones == "") observaciones = "✅ Todos los parámetros dentro del rango normal.";

    ficha += observaciones;
    Serial.println(ficha);
    return ficha;
}