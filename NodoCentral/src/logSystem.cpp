//************************************************************
// Author: Jesús Muñoz Martínez
// Project: Trabajo Fin de Master: LUCES.
// Master de Sistemas Electrónicos para Entornos Inteligentes
// Root Node.
// Description: Cpp file from logSystem to implement log status
//
//************************************************************


#include "logSystem.h"
#include <logger_spiffs.h>
#include <Arduino_JSON.h>


// file for logging
LoggerSPIFFS myLog("/lucesLog.txt");
int counter = 0;



bool circularFile(char* buffer, int n){
  if (counter == 1){
    counter = 0;
    return false;
  }else{
    counter ++;
  return true;
  }
}

void initLog(){
  myLog.begin();
  myLog.setSizeLimit(100000);  // 100k Kbytes
  myLog.setSizeLimitPerChunk(280);  //bytes
  myLog.setFlusherCallback(circularFile);
}


void logging(String msg)
{
  
  time_t now = time(nullptr);
  String mytime = ctime (&now);
  mytime.remove (24, 2);
  msg = mytime +": "+ msg;

  if(myLog.isFull()){
    myLog.flush();
    bool success = myLog.append(msg.c_str(), false);
    if(success){
      Serial.println("FS: Event stored!");
    }else {
      Serial.println("FS: Event NOT stored, file is full!");
    }
  }else{
    bool success = myLog.append(msg.c_str(), false);
    if(success){
      Serial.println("FS: Event stored!");
    }else {
      Serial.println("FS: Event NOT stored!");
      myLog.flush();
    }
  }  
}

  
bool clear(char* buffer, int n){
  return true;
}


void clearLog()
{
  myLog.setFlusherCallback(clear);
  myLog.flush();
  myLog.setFlusherCallback(circularFile);
  Serial.println("FS: Log cleared!");
}

