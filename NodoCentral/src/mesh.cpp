//************************************************************
// Author: Jesús Muñoz Martínez
// Project: Trabajo Fin de Master: LUCES.
// Master de Sistemas Electrónicos para Entornos Inteligentes
// Root Node.
// Description: file mesh.cpp
// MESH NETWORK functions.
//
//************************************************************

#include "mesh.h"
#include "utils.h"
#include "controlMsg.h"


painlessMesh  mesh;
bool calc_delay = false;
SimpleList<uint32_t> nodes;
IPAddress MESHIP(0,0,0,0);
IPAddress BHIP(0,0,0,0);


extern Task taskNTPSync;
extern Task taskCheckBHIP;



void sendMessage (String msg) {
    mesh.sendBroadcast(msg);
    Serial.printf("MESH: Sent: %s\n", msg.c_str());
    //logging(msg);
}


void receivedCallback(uint32_t from, String & msg) {
    Serial.printf("MESH: Received msg=%s\n", msg.c_str());
    JSONVar myObject = JSON.parse(msg.c_str());
    if (strcmp(myObject["type"], "F") == 0) {  //fail message received
      int node = atoi(myObject["node"]);
      sendEmail(node);
    }
    notifyClients(msg);
    logging(msg);
}

void newConnectionCallback(uint32_t nodeId) {

  Serial.printf("MESH: New Connection, nodeId = %u\n", nodeId);
  Serial.printf("MESH: New Connection, %s\n", mesh.subConnectionJson(true).c_str());
  syncTimeNode();
}

void changedConnectionCallback() {
  Serial.printf("MESH: Changed connections\n");
 
  nodes = mesh.getNodeList();

  Serial.printf("MESH: Num nodes: %d\n", nodes.size());
  Serial.printf("MESH: Connection list:");

  SimpleList<uint32_t>::iterator node = nodes.begin();
  while (node != nodes.end()) {
    Serial.printf(" %u", *node);
    node++;
  }
  Serial.println();
  calc_delay = true;
}

void nodeTimeAdjustedCallback(int32_t offset) {
  Serial.printf("MESH: Adjusted time %u. Offset = %d\n", mesh.getNodeTime(), offset);
}

void delayReceivedCallback(uint32_t from, int32_t delay) {
  Serial.printf("MESH: Delay to node %u is %d us\n", from, delay);
}

IPAddress getlocalIP() {
  return IPAddress(mesh.getStationIP());
}

void updateMesh(){
    mesh.update();
}


void initMesh(){
  
  // mesh.setDebugMsgTypes( ERROR | MESH_STATUS | CONNECTION | SYNC |
  // COMMUNICATION | GENERAL | MSG_TYPES | REMOTE ); // all types on
  mesh.setDebugMsgTypes(ERROR | DEBUG);  // set before init() so that you can see error messages

  
  mesh.init(MESH_SSID, MESH_PASSWORD, &userScheduler, MESH_PORT, WIFI_AP_STA, CHANNEL );
  mesh.onReceive(&receivedCallback);
  mesh.onNewConnection(&newConnectionCallback);
  mesh.onChangedConnections(&changedConnectionCallback);
  mesh.onNodeTimeAdjusted(&nodeTimeAdjustedCallback);
  mesh.onNodeDelayReceived(&delayReceivedCallback);
  mesh.initOTAReceive("root");  //Añade soporte para actualizaciones en remoto. Acepta firmwares nombrados como root.

  mesh.stationManual(getSSID(), getPasswd());
  mesh.setHostname(HOSTNAME);

  // Bridge node, should (in most cases) be a root node.
  mesh.setRoot(true);
  // This node and all other nodes should ideally know the mesh contains a root, so call this on all nodes
  mesh.setContainsRoot(true);

  MESHIP = IPAddress(mesh.getAPIP());
  Serial.println("My MESH IP is " + MESHIP.toString());
}


void checkBHIP(){
    if(BHIP != getlocalIP()){
    BHIP = getlocalIP();
    Serial.println("My Backhaul IP is " + BHIP.toString());
    taskNTPSync.enable();
    taskCheckBHIP.setInterval( random(TASK_SECOND * 1, TASK_SECOND * 3));
  }
}