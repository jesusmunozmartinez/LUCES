//************************************************************
// Author: Jesús Muñoz Martínez
// Project: Trabajo Fin de Master: LUCES.
// Master de Sistemas Electrónicos para Entornos Inteligentes
// Root Node.
// Description: Header file from logger to implement log status
//
//************************************************************

#ifndef WEBSERVERCP_H
#define WEBSERVERCP_H

#include <Arduino_JSON.h>
#include "AsyncTCP.h"
#include "ESPAsyncWebServer.h"


void notifyClients(String message);
void handleWebSocketMessage(void *arg, uint8_t *data, size_t len);
void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len);
void initWebSocket();
void initWebServer();
void wsCleanupClients();

#endif // END WEBSERVERCP_H

