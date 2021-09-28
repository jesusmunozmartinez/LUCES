//************************************************************
// Author: Jesús Muñoz Martínez
// Project: Trabajo Fin de Master: LUCES.
// Master de Sistemas Electrónicos para Entornos Inteligentes
// Root Node.
// Description: configFile.h file
//
//************************************************************


#ifndef CONFIGFILE_H
#define CONFIGFILE_H

#include "config.h"
#include <Arduino_JSON.h>


String loadConfig();
void saveConfig(JSONVar myJson);
JSONVar loadConfigMode();
void saveConfigMode(String configModeStr);
void gotoConfigMode();


#endif // END CONFIGFILE_H