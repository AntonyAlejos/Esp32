#include "GestorDatos.h"
#include <SD.h>

GestorDatos::GestorDatos(FichaMedica& ficha):ficha(ficha){
    SD.begin();
    // Podés inicializar SD, WiFi, etc. aquí si querés
}

bool GestorDatos::recibirDesdeSerial(Paciente &paciente) {
    if (Serial2.available()) {
        String linea = Serial2.readStringUntil('\n');
        linea.trim();

        if (linea.length() > 0) {
            paciente = parsearDesdeCSV(linea);
            return true;
        }
    }
    return false;
}

Paciente GestorDatos::parsearDesdeCSV(const String& lineaOriginal) {
    String partes[7];
    int index = 0;
    String linea = lineaOriginal;

    while (index < 7) {
        int pos = linea.indexOf(',');
        if (pos == -1) {
            partes[index++] = linea;
            break;
        }
        partes[index++] = linea.substring(0, pos);
        linea = linea.substring(pos + 1);
    }

    Paciente p;
    p.setNombre(partes[0]);
    p.setApellido(partes[1]);
    p.setID(partes[2].toInt());
    (p.getExamen()).setTemperatura(partes[3].toFloat());
    (p.getExamen()).setFrecuencia(partes[4].toInt()); 
    (p.getExamen()).setSpo2( partes[5].toInt());
    (p.getExamen()).setFecha(partes[6]);
    return p;
}

void GestorDatos::guardarEnSD(  Paciente &paciente) {
   
    File file = SD.open("/registros.csv",FILE_WRITE);
   
    if (file) {
        file.printf("%s,%s,%d,%.1f,%d,%d,%s\n",
            paciente.getNombre().c_str(),
            paciente.getApellido().c_str(),
            paciente.getID(),
            paciente.getExamen().getTemperatura(),
            paciente.getExamen().getFrecuenciaCardiaca(),
            paciente.getExamen().getSpo2(),
            paciente.getExamen().getFecha().c_str()
        );
        file.close();
    } else {
        Serial.println("❌ Error al guardar en SD");
    }
}

String GestorDatos::enviarATelegram(Paciente &paciente) {
    
    return ficha.generarFicha(paciente);;
    // Aquí deberías usar la API que estés usando para enviar a Telegram
    // Por ejemplo: TelegramBot.sendMessage(chat_id, mensaje, "Markdown");
}
