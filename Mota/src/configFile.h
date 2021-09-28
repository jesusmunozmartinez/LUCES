//************************************************************
// Author: Jesús Muñoz Martínez
// Proyect: Trabajo Fin de Master: LUCES.
// Master de Sistemas Electrónicos para Entornos Inteligentes
// MOta Node.
// Description: configFile.h file
//
//************************************************************


#ifndef CONFIGFILE_H
#define CONFIGFILE_H

#include "config.h"
#include <Arduino_JSON.h>

void initFS();
void writeConfig();
void loadConfig();
void saveConfig();

#endif // END CONFIGFILE_H