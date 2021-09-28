//************************************************************
// Author: Jesús Muñoz Martínez
// Project: Trabajo Fin de Master: LUCES.
// Master de Sistemas Electrónicos para Entornos Inteligentes
// Root Node.
// Description: Header file from mesh.cpp
//
//************************************************************


#ifndef MESH_H
#define MESH_H

#include <Arduino.h>
#include "config.h"
#include <painlessMesh.h>
#include <Arduino_JSON.h>
#include "logSystem.h"
#include "webServerCP.h"


extern Scheduler     userScheduler; 

void sendMessage(String msg);
void receivedCallback(uint32_t from, String & msg);
void newConnectionCallback(uint32_t nodeId);
void changedConnectionCallback(); 
void nodeTimeAdjustedCallback(int32_t offset); 
void delayReceivedCallback(uint32_t from, int32_t delay);
IPAddress getlocalIP();
void updateMesh();
void initMesh();
void checkBHIP();


#endif // END MESH_H
