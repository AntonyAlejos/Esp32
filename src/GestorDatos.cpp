#include "GestorDatos.h"
#include <SD.h>

GestorDatos::GestorDatos(FichaMedica& ficha):ficha(ficha){
    SD.begin();
    // Podés inicializar SD, WiFi, etc. aquí si querés
}

bool GestorDatos::recibirDesdeSerial(String &linea) {
    if (Serial2.available()) {
        linea = Serial2.readStringUntil('\n');
        linea.trim();
        return(linea.length()>0);
    }
    return false;
}

Paciente GestorDatos::parsearDesdeCSV(const String& lineaOriginal) {
    String partes[13];
    int index = 0;
    String linea = lineaOriginal;

    while (index < 13) {
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
    p.setEdad(partes[2].toInt());
    p.setSexo(partes[3][0]);
    p.setDomicilio(partes[4]);
    p.setTelefono(partes[5]);
    p.setContactoEmerg(partes[6]);

    Examen ex;
    ex.setFecha(partes[7]);
    ex.setOxigeno(partes[8].toFloat());
    ex.setPulso(partes[9].toFloat());
    ex.setTemperatura(partes[10].toFloat());
    ex.setPresionS(partes[11].toFloat());
    ex.setPresionD(partes[12].toFloat());
    //ex.setDiagnostico(partes[13]);
    Serial.println("=== CSV recibido ===");
    Serial.println(lineaOriginal);
    for (int i = 0; i < 13; i++) {
    Serial.print("Parte ");
    Serial.print(i);
    Serial.print(": [");
    Serial.print(partes[i]);
    Serial.println("]");
}


    p.setExamen(ex);
    return p;
}

void GestorDatos::guardarEnSD(  Paciente &paciente) {
   
    File file = SD.open("/registros.csv",FILE_WRITE);
   
    if (file) {
        file.printf("%s,%s,%d,%.2f,%.2f,%.2f,%.2f,%.2f,%s\n",
            paciente.getNombre().c_str(),
            paciente.getApellido().c_str(),
            paciente.getEdad(),
            paciente.getExamen().getOxigeno(),
            paciente.getExamen().getPulso(),
            paciente.getExamen().getTemperatura(),
            paciente.getExamen().getPresionS(),
            paciente.getExamen().getPresionD(),
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
