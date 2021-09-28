//************************************************************
// Author: Jesús Muñoz Martínez
// Proyect: Trabajo Fin de Master: LUCES.
// Master de Sistemas Electrónicos para Entornos Inteligentes
// MOta Node.
// Description: readSensors.cpp file
//
//************************************************************

#include "config.h"
#include "readsensors.h"
#include <BH1750.h>
#include <Arduino_JSON.h>
#include "mesh.h"
#include "controlLum.h"
#include "utils.h"


extern painlessMesh  mesh;
extern bool onStatus;
extern bool onPresence;
extern int bright;
extern int luxes;
int failCount=0;

extern Task taskCheckPresence;

//Bh1750 object on the default I2C pins
BH1750 lightmeter;
float CurrentSensity=0.185; //sensibilidad en Voltios/Amperio para sensor ACS712 de 5A

//Init BH1750 sensor
void initBH1750(){
  if (!lightmeter.begin()) {
    Serial.println("Could not find a valid BH1750 sensor, check wiring!");
    while (1);
  }  
}


float readCurrent() {
  float voltageSensor, current;
  int nMuestras = 10;
  for (int i=0; i<nMuestras;i++){
    voltageSensor= analogRead(A0)*(3.2/ 1024.0);    
    current=current + (voltageSensor-2.50)/CurrentSensity; 
  }
  current = current/nMuestras;
  return current;
}


String checkFail(float I){
  String fail = "NO";
  
  if((onStatus)&&(I<0.1)){ 
    fail = "SI";
    failCount++;
  }else{
    fail = "NO";
  }
  if (failCount == 20) {
    JSONVar JsonFail;
    String node = meshNodeId();
    JsonFail["node"] = node;
    JsonFail["type"] = "F"; //F: fail mensagge
    String msgFail = JSON.stringify(JsonFail);
    mesh.sendBroadcast(msgFail);
  }
   return fail;
}



String getReadings () {
  JSONVar JsonReadings;

  String node = meshNodeId();
  float current = readCurrent();
  String currentStr = String (current, 3);
  luxes = lightmeter.readLightLevel();
  String luxesStr = String(luxes);
  node.remove(1,6);
  String onOff;
  if (onStatus){
    onOff = "ON";
  } else{
    onOff = "OFF";
  }
  printLocalTime();
  JsonReadings["node"] = node;
  JsonReadings["type"] = "S"; //S: info from sensors
  JsonReadings["lux"] = luxesStr;
  JsonReadings["I"] = currentStr;
  onPresence = digitalRead(PIRpin);
  JsonReadings["pir"] = onPresence;
  JsonReadings["onOff"] = onOff;
  JsonReadings["bright"] = String(bright);
  JsonReadings["fail"] = checkFail(current);
  String readings = JSON.stringify(JsonReadings);
  return readings;
}