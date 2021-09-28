//************************************************************
// Author: Jesús Muñoz Martínez
// Project: Trabajo Fin de Master: LUCES.
// Master de Sistemas Electrónicos para Entornos Inteligentes
// Root Node.
// Description: Header file from utils.cpp
//
//************************************************************

#ifndef UTILS_H
#define UTILS_H

#include "config.h"
#include "time.h"
#include <painlessMesh.h>

void initFS();
void syncTimeNode();
bool printLocalTime();
void ntpSync();
void printFwVersion();
bool isConfigMode();
String getSSID();
String getPasswd();


#endif // END UTILS_H

