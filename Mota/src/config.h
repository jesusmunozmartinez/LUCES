//************************************************************
// Author: Jesús Muñoz Martínez
// Proyect: Trabajo Fin de Master: LUCES.
// Master de Sistemas Electrónicos para Entornos Inteligentes
// Root Node.
// Description: Configuration file
//
//************************************************************



#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino_JSON.h>

const   String verFw = "Luces_ESP8266_mota_080921.bin";

// MESH configuration
#define   MESH_SSID       "LucesMesh"
#define   MESH_PASSWORD   "Password1"
#define   MESH_PORT       5555


#define    LED             2       // GPIO number of connected LED, ON ESP-12 IS GPIO2
#define    BLINK_PERIOD    3000    // milliseconds until cycle repeat
#define    BLINK_DURATION  100     // milliseconds LED is on for
#define    PIRpin          12       // GPIO number of connected PIR SENSOR: GPIO4

#define    PWM             13       // GPIO number of connected PWM, 1.-10v CONTROL
#define    TRIAC           15       // GPIO for TRIAC control
#define    ZC              D5       // GPIO for Zero cross interruption

#endif // END CONFIG_H