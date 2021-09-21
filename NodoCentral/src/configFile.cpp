//************************************************************
// Author: Jesús Muñoz Martínez
// Project: Trabajo Fin de Master: LUCES.
// Master de Sistemas Electrónicos para Entornos Inteligentes
// Root Node.
// Description: configFile.cpp file
//
//************************************************************


#include "configFile.h"
#include "SPIFFS.h"




String loadConfig(){

  File file = SPIFFS.open("/config.txt", "r");
  String config; 
  if (!file) {
    Serial.println("Failed to open file for reading");
  }
  while (file.available()) {
    config += char(file.read()); 
  }
  file.close();
  Serial.println("Load File Config:");
  Serial.println(config);
  return config;
}


void saveConfig(JSONVar myJson){
    File file = SPIFFS.open("/config.txt", "w");
    if(!file){
        // File not found
        Serial.println("Error opening file for writing");
        return;
    } else {
    int bytesWritten = file.print(myJson);
    if (bytesWritten == 0) {
        Serial.println("File write failed");
        return;
    }
    file.close();
    }
}

JSONVar loadConfigMode(){
  File file = SPIFFS.open("/configMode", "r");
  String configMode; 
  if (!file) {
    Serial.println("Failed to open file for reading");
  }
  while (file.available()) {
    configMode += char(file.read()); 
  }
  file.close();
  JSONVar jsonConfigMode = JSON.parse(configMode.c_str());
  return jsonConfigMode;
}
 


void saveConfigMode(String configModeStr){
    File file = SPIFFS.open("/configMode", "w");
    if(!file){
        // File not found
        Serial.println("Error opening file for writing");
        return;
    } else {
    int bytesWritten = file.print(configModeStr);
    if (bytesWritten == 0) {
        Serial.println("File write failed");
        return;
    }
    file.close();
    }
}

void gotoConfigMode(){
  JSONVar jsonConfMode;
  jsonConfMode["status"] = "true";
  jsonConfMode["ssid"] = "";
  jsonConfMode["passwd"] = "";
  String configMsg = JSON.stringify(jsonConfMode);
  saveConfigMode(configMsg);
  Serial.println("Go to config mode");
  Serial.println("Rebooting...");
  ESP.restart();
}