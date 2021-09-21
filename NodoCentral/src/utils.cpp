//************************************************************
// Author: Jesús Muñoz Martínez
// Project: Trabajo Fin de Master: LUCES.
// Master de Sistemas Electrónicos para Entornos Inteligentes
// Root Node.
// Description: utils.cpp file
//
//************************************************************


#include "utils.h"
#include "logSystem.h"
#include "SPIFFS.h"
#include "mesh.h"
#include "configFile.h"



const char* ntpServer = NTPSERVER;
const long  gmtOffset_sec = GMTOFFSEC_SEC;    //offset from GMT. 3600 from Spain
const int   daylightOffset_sec = DAYLIGHTOFFSET;

extern const char* const verFw;

extern Task taskNTPSync; // start with a hour interval


void initFS() {
  if (!SPIFFS.begin()) {
    Serial.println("An error has occurred while mounting SPIFFS");
  }
  else{
   Serial.println("SPIFFS mounted successfully");
  }
}

void syncTimeNode(){

  JSONVar jsonTime;
  time_t now = time(nullptr);
  jsonTime["type"] = "T"; // T: Time control messages
  jsonTime["time"] = now;  //epoch time
  jsonTime["hOffset"] = 2;  //for local time adjust
  String timeMsg = JSON.stringify(jsonTime);
  sendMessage(timeMsg);
}


bool printLocalTime()
{
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    Serial.println("Failed to obtain time");
    return false;
  }
  Serial.print("NTP Sync: ");
  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
  time_t now = time(nullptr);
  String msg = "NTP sync: " + String((ctime(&now)));
  logging(msg);
  return true;  
}



void ntpSync() {
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
    bool success = printLocalTime();
    if (success){
       taskNTPSync.setInterval( random(TASK_SECOND * 3600*10, TASK_SECOND * 3600*12));  // between 10 and 12 hours
       syncTimeNode();
    }
}


void printFwVersion()
{
  Serial.println(" ");
  Serial.print("Firware version: ");
  Serial.println(verFw);
}


bool isConfigMode(){
  JSONVar jsonConfig = loadConfigMode();
  bool configMode;
  if (strcmp(jsonConfig["status"], "true") == 0){
    configMode = true;
  }else{
    configMode = false;
  }
  return configMode;
}


String getSSID(){
  JSONVar jsonConfig = loadConfigMode();
  JSONVar jsonssid = jsonConfig["ssid"];
  String mySsid = JSON.stringify(jsonssid);
  int last =mySsid.length()-1;
  mySsid = mySsid.substring(1,last);
  return mySsid;
}


String getPasswd(){
  JSONVar jsonConfig = loadConfigMode();
  JSONVar jsonpass = jsonConfig["passwd"];
  String pass = JSON.stringify(jsonpass);
  int last =pass.length()-1;
  pass = pass.substring(1,last);
 
  return pass;
}

