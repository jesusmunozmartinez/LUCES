//************************************************************
// Author: Jesús Muñoz Martínez
// Proyect: Trabajo Fin de Master: LUCES.
// Master de Sistemas Electrónicos para Entornos Inteligentes
// MOta Node.
// Description: configFile.cpp file
//
//************************************************************

#include "configFile.h"
#include <LittleFS.h>

extern JSONVar config;
extern bool onStatus;
extern int bright; 
   

void initFS() {
  if (!LittleFS.begin()) {
    Serial.println("An error has occurred while mounting SPIFFS");
  }
  else{
   Serial.println("LittleFS mounted successfully");
  }
}


void writeConfig(){
File file = LittleFS.open("/config.txt", "w");
 
if (!file) {
    Serial.println("Error opening file for writing");
    return;
}
 
int bytesWritten = file.print("TEST FILE");
 
if (bytesWritten == 0) {
    Serial.println("File write failed");
    return;
}

file.close();
}


void loadConfig(){

  File file = LittleFS.open("/config.txt", "r");
  String configStr; 
  if (!file) {
    Serial.println("Failed to open file for reading");
  }
  while (file.available()) {
    configStr += char(file.read()); 
  }
  file.close();
  Serial.println("Load File Config:"+configStr);
  config = JSON.parse(configStr.c_str());
   if (strcmp(config["mOn"], "on") == 0) {
      onStatus = true;
   }else{
      onStatus = false;
   }   
  bright = atoi(config["bVal"]);  
}
//Example config message:
//{"type":"config","mode":"manual","mOn":"Off","mLux":"1000","mT1":"21:37","mT2":"07:53","Lum":"manual","bVal":"80","bT1":"20:37","bT2":"22:37","bT3":"02:37","bT4":"04:37","bT1Lux":"50","bT2Lux":"100","bT3Lux":"80","bT4Lux":"100","bPre":"52"}

void saveConfig(){
    File file = LittleFS.open("/config.txt", "w");
    if(!file){
        // File not found
        Serial.println("Error opening file for writing");
        return;
    } else {
    int bytesWritten = file.print(config);
    if (bytesWritten == 0) {
        Serial.println("File write failed");
        return;
    }
    file.close();
    Serial.println("Save File Config:");
    Serial.println(config);
    }
}