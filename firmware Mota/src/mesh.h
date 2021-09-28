//************************************************************
// Author: Jesús Muñoz Martínez
// Proyect: Trabajo Fin de Master: LUCES.
// Master de Sistemas Electrónicos para Entornos Inteligentes
// Mota Node.
// Description: Header file from mesh.cpp
//
//************************************************************


#ifndef MESH_H
#define MESH_H

#include <Arduino.h>
#include "config.h"
#include <painlessMesh.h>
#include <Arduino_JSON.h>
#include "readSensors.h"

extern painlessMesh  mesh;
extern Scheduler     userScheduler; 

String meshNodeId();
void sendMessageStatus();
void receivedCallback(uint32_t from, String & msg);
void newConnectionCallback(uint32_t nodeId);
void changedConnectionCallback(); 
void nodeTimeAdjustedCallback(int32_t offset); 
void delayReceivedCallback(uint32_t from, int32_t delay);
void updateMesh();
void initMesh();

#endif // END MESH_H