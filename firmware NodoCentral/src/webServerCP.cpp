//************************************************************
// Author: Jesús Muñoz Martínez
// Project: LUCES.
// Trabajo Fin de Master. 
// Master de Sistemas Electrónicos para Entornos Inteligentes
//
// Nodo Root
//
// Web Server
//************************************************************


#include "webServerCP.h"
#include "SPIFFS.h"
#include "configFile.h"
#include "controlMsg.h"
#include "logSystem.h"



AsyncWebServer server(80);   // Create AsyncWebServer object on port 80
AsyncWebSocket ws("/ws");    // Create a WebSocket object

String message = "";


//Get Slider and other Values

void sendConfigValues(){
  String message = loadConfig();
  ws.textAll(message);
}


// function notifies all clients with the current slider values. 
// Calling this function is what allows us to notify changes in all clients whenever
// you set a new position for a slider.
void notifyClients(String message) {
  ws.textAll(message);
}



// handles what happens when the server receives a message from the client via WebSocket protocol

void handleWebSocketMessage(void *arg, uint8_t *data, size_t len) {
  AwsFrameInfo *info = (AwsFrameInfo*)arg;
  if (info->final && info->index == 0 && info->len == len && info->opcode == WS_TEXT) {
    data[len] = 0;
    message = (char*)data;
    Serial.println("Web: msg received!: "+ message);
    JSONVar myMsg = JSON.parse(message.c_str());
    if (strcmp(myMsg["type"], "getConfig") == 0) {
      sendConfigValues();
    }
    if (strcmp(myMsg["type"], "pValues") == 0){
      notifyClients(message);
      saveConfig(myMsg);
      sendConfig2Nodes();
    }
    if (strcmp(myMsg["type"], "clearLog") == 0) {
      clearLog();
    }
    if (strcmp(myMsg["type"], "gotoConfig") == 0) {
      gotoConfigMode();
    }
  }
}


void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len) {
  switch (type) {
    case WS_EVT_CONNECT:
      Serial.printf("WebSocket client #%u connected from %s\n", client->id(), client->remoteIP().toString().c_str());
      break;
    case WS_EVT_DISCONNECT:
      Serial.printf("WebSocket client #%u disconnected\n", client->id());
      break;
    case WS_EVT_DATA:
      handleWebSocketMessage(arg, data, len);
      break;
    case WS_EVT_PONG:
    case WS_EVT_ERROR:
      break;
  }
}

void initWebSocket() {
  ws.onEvent(onEvent);
  server.addHandler(&ws);
}


void initWebServer() {
  initWebSocket();
  // Web Server Root URL
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/index.html", "text/html");
  });
   server.serveStatic("/", SPIFFS, "/");
  // Start server
  server.begin();
}

void wsCleanupClients() {
  ws.cleanupClients();
}