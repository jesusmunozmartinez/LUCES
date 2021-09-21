//************************************************************
// Author: Jesús Muñoz Martínez
// Project: Trabajo Fin de Master: LUCES.
// Master de Sistemas Electrónicos para Entornos Inteligentes
// Root Node.
// Description: Header file from controlMsg.cpp
//
//************************************************************

#ifndef CONTROLMSG_H
#define CONTROLMSG_H

#include <Arduino_JSON.h>

void sendConfig2Nodes();
void sendEmail(int node);

#endif // END CONTROLMSG_H
