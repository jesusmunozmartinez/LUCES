//************************************************************
// Author: Jesús Muñoz Martínez
// Project: Trabajo Fin de Master: LUCES.
// Master de Sistemas Electrónicos para Entornos Inteligentes
// Root Node.
// Description: Header file from logger to implement log status
//
//************************************************************

#ifndef LOGSYSTEN_H
#define LOGSYSTEM_H

#include <Arduino_JSON.h>
#include <Arduino.h>


    void initLog();

    // append to log an event
    void logging(String msg);

    //clear log file
    void clearLog();

#endif // END LOGSYSTEM_H

