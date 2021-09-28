//************************************************************
// Author: Jesús Muñoz Martínez
// Proyect: Trabajo Fin de Master: LUCES.
// Master de Sistemas Electrónicos para Entornos Inteligentes
// Mota Node.
// Description: Header file from utils.cpp
//
//************************************************************

#ifndef UTILS_H
#define UTILS_H

#include "config.h"
#include "time.h"
#include <painlessMesh.h>
#include <Arduino_JSON.h>

void printLocalTime();
void syncTime(JSONVar jsonTime);
void printFwVersion();

#endif // END UTILS_H