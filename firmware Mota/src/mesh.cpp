//************************************************************
// Author: Jesús Muñoz Martínez
// Proyect: Trabajo Fin de Master: LUCES.
// Master de Sistemas Electrónicos para Entornos Inteligentes
// MOta Node.
// Description: file mesh.cpp
// MESH NETWORK functions.
//
//************************************************************

#include "mesh.h"
#include "Arduino.h"
#include "utils.h"
#include "configFile.h"


bool calc_delay = false;;
SimpleList<uint32_t> nodes;
extern bool onFlag;
extern JSONVar config;

extern Task taskBlinkNoNodes;
extern Task taskSendStatus;


String meshNodeId(){
    String msg = String(mesh.getNodeId());
    return msg;
}


void sendMessageStatus () {
  String msg = getReadings();
  mesh.sendBroadcast(msg);
  if (calc_delay) {
    SimpleList<uint32_t>::iterator node = nodes.begin();
    while (node != nodes.end()) {
      mesh.startDelayMeas(*node);
      node++;
    }
    calc_delay = false;
  }
  Serial.printf("Broadcast: %s\n", msg.c_str());
  taskSendStatus.setInterval( random(TASK_SECOND * 1, TASK_SECOND * 2));  // between 5 and 10 seconds
}



void newConnectionCallback(uint32_t nodeId) {
  Serial.printf("New Connection, nodeId = %u\n", nodeId);
  Serial.printf("New Connection, %s\n", mesh.subConnectionJson(true).c_str());
}




void receivedCallback(uint32_t from, String & msg) {
  Serial.printf("Received from %u msg=%s\n", from, msg.c_str());
  JSONVar myMsg = JSON.parse(msg.c_str());
  if (strcmp(myMsg["type"], "C") == 0) {
    config = JSON.parse(msg.c_str());
    saveConfig();
  }
  if (strcmp(myMsg["type"], "T") == 0) {
    syncTime(myMsg);
  }
}



void changedConnectionCallback() {
  Serial.printf("Changed connections\n");
  // Reset blink task
  onFlag = false;
  taskBlinkNoNodes.setIterations((mesh.getNodeList().size() + 1) * 2);
  taskBlinkNoNodes.enableDelayed(BLINK_PERIOD - (mesh.getNodeTime() % (BLINK_PERIOD*1000))/1000);
  nodes = mesh.getNodeList();
  Serial.printf("Num nodes: %d\n", nodes.size());
  Serial.printf("Connection list:");
  SimpleList<uint32_t>::iterator node = nodes.begin();
  while (node != nodes.end()) {
    Serial.printf(" %u", *node);
    node++;
  }
  Serial.println();
  calc_delay = true;
}


void nodeTimeAdjustedCallback(int32_t offset) {
  Serial.printf("Adjusted time %u. Offset = %d\n", mesh.getNodeTime(), offset);
}

void delayReceivedCallback(uint32_t from, int32_t delay) {
  Serial.printf("Delay to node %u is %d us\n", from, delay);
}


void updateMesh(){
    mesh.update();
}


void initMesh(){
  // mesh.setDebugMsgTypes( ERROR | MESH_STATUS | CONNECTION | SYNC |
  // COMMUNICATION | GENERAL | MSG_TYPES | REMOTE ); // all types on
  mesh.setDebugMsgTypes(ERROR | DEBUG);  // set before init() so that you can see error messages
  mesh.init(MESH_SSID, MESH_PASSWORD, &userScheduler, MESH_PORT);
  mesh.onReceive(&receivedCallback);
  mesh.onNewConnection(&newConnectionCallback);
  mesh.onChangedConnections(&changedConnectionCallback);
  mesh.onNodeTimeAdjusted(&nodeTimeAdjustedCallback);
  mesh.onNodeDelayReceived(&delayReceivedCallback);
  mesh.initOTAReceive("mota");  // OTA firmware support.
}