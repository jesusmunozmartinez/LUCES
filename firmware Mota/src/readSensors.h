//************************************************************
// Author: Jesús Muñoz Martínez
// Proyect: Trabajo Fin de Master: LUCES.
// Master de Sistemas Electrónicos para Entornos Inteligentes
// MOta Node.
// Description: readSensors.h file
//
//************************************************************


#ifndef READSENSORS_H
#define READSENSORS_H

#include "config.h"
#include <Arduino_JSON.h>

void initBH1750();
float readCurrent();
String getReadings();


#endif // END READSENSORS_H