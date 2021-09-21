//************************************************************
// Author: Jesús Muñoz Martínez
// Project: LUCES.
// Trabajo Fin de Master. 
// Master de Sistemas Electrónicos para Entornos Inteligentes
// Root node running in ESP32 device.
//  - OTA support 
//  - Web Server with panel control
//  - NTP service to sync internet time
//  - System Log
//  - Save / restore Config File
//  - bridge backhaul <-> Mesh network
//  - send an email with error message
//
//************************************************************

#include <Arduino.h>
#include "IPAddress.h"
#include <painlessMesh.h>

#include "config.h"        // system configuration file
#include "logSystem.h"
#include "webServerCP.h"
#include "utils.h"
#include "mesh.h"
#include "initSetup.h"
#include "configFile.h"



bool configMode = true;

Scheduler  userScheduler; // to control tasks

// Task Handlers, constructor

Task taskNTPSync( TASK_SECOND * 3, TASK_FOREVER, &ntpSync ); // utils.cpp
Task taskWsCleanup( TASK_SECOND * 1, TASK_FOREVER, &wsCleanupClients ); 
Task taskCheckBHIP(TASK_SECOND * 1, TASK_FOREVER, &checkBHIP);
Task taskGotoConfig(TASK_SECOND * 1, TASK_FOREVER, &gotoConfigMode);


//-------- ISR -----------------
void IRAM_ATTR isr() {
  Serial.println("ISR");
  taskGotoConfig.enable();
}

// ------------------- SETUP ------------------------
void setup() {
  Serial.begin(115200);
  printFwVersion();
  initFS();
  configMode = isConfigMode();
  if (configMode){
      configModeStart();
  }else{
    pinMode(0, INPUT_PULLUP);
    attachInterrupt(0, isr, FALLING);
    initMesh();
    initWebServer();
    initLog();  

    //--- Task NTP syncronize --
    userScheduler.addTask( taskNTPSync );
    
    //--- Task websocket clean clients --
    userScheduler.addTask( taskWsCleanup );
    taskWsCleanup.enable();

      //--- Task check backhaulIP --
    userScheduler.addTask( taskCheckBHIP );
    taskCheckBHIP.enable();

    //--- Task go to config modeP --
    userScheduler.addTask( taskGotoConfig );

    randomSeed(analogRead(A0));
  }
}

// -------------- Loop ---------------------------

void loop() {
  if (!configMode){
      updateMesh();
  }  
}
