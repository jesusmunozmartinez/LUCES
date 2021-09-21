//************************************************************
// Author: Jesús Muñoz Martínez
// Project: Trabajo Fin de Master: LUCES.
// Master de Sistemas Electrónicos para Entornos Inteligentes
// Root Node.
// Description: initSetup.cpp file
//
//************************************************************


#include "initSetup.h"
#include <WiFi.h>  
#include <WebServer.h>
#include <DNSServer.h>
#include <WiFiManager.h>
#include "configFile.h"


WiFiManager wifiManager;


void configModeCallback (WiFiManager *myWiFiManager) {
 Serial.println("Modo de configuración activado");
 Serial.println(WiFi.softAPIP());
 
 Serial.println(myWiFiManager->getConfigPortalSSID());
}
 
 
void saveConfigCallback () {
  JSONVar jsonConfMode;
  jsonConfMode["status"] = "false";
  jsonConfMode["ssid"] = wifiManager.getWiFiSSID();
  jsonConfMode["passwd"] = wifiManager.getWiFiPass();
  String configMsg = JSON.stringify(jsonConfMode);
  saveConfigMode(configMsg);
  Serial.println("Configuration saved");
}


void configModeStart() {
  wifiManager.setAPCallback(configModeCallback);
  wifiManager.setSaveConfigCallback(saveConfigCallback);
  if(!wifiManager.startConfigPortal("LUCES_CONFIG") ){
    Serial.println("No se pudo conectar");
  }
  Serial.println("Rebooting...");
  ESP.restart();
}

