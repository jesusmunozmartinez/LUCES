//************************************************************
// Author: Jesús Muñoz Martínez
// Proyect: Trabajo Fin de Master: LUCES.
// Master de Sistemas Electrónicos para Entornos Inteligentes
// Mota Node.
// Description: utils.cpp file
//
//************************************************************


#include "utils.h"
#include "mesh.h"
#include <TimeLib.h>


void printLocalTime()
{
  time_t t = now();
  String msg = "Time: " + String((ctime(&t)));
  Serial.println(msg);
}


void syncTime(JSONVar jsonTime){
  
  JSONVar value = jsonTime["time"]; 
  String jsonString = JSON.stringify(value);
  time_t myTime = jsonString.toInt();
  setTime(myTime);
  value = jsonTime["hOffset"]; 
  jsonString = JSON.stringify(value);
  int h = jsonString.toInt();
  adjustTime(h*3600);
}

void printFwVersion()
{
  Serial.println(" ");
  Serial.println("Firware version: "+verFw);
}