//************************************************************
// Author: Jesús Muñoz Martínez
// Project: Trabajo Fin de Master: LUCES.
// Master de Sistemas Electrónicos para Entornos Inteligentes
// Root Node.
// Description: Configuration file
//
//************************************************************


#ifndef CONFIG_H
#define CONFIG_H

const   char* const verFw = "Luces_ESP32_root_110921.bin";


// MESH configuration
#define   MESH_SSID       "LucesMesh"
#define   MESH_PASSWORD   "Password1"
#define   MESH_PORT       5555

// Backhaul Network 
#define   STATION_SSID     ""   //deprecated, use WiFiManager
#define   STATION_PASSWORD ""   //deprecated, use WiFiManager
#define   STATION_PORT     5555
#define   HOSTNAME         "LUCES"
#define   CHANNEL          1     // Make sure to use the same channel for your mesh and backhaul network

// NPT client
#define   NTPSERVER        "pool.ntp.org"
#define   GMTOFFSEC_SEC    3600    //offset from GMT. 3600 from Spain
#define   DAYLIGHTOFFSET   3600

// mail client
#define SMTP_HOST "smtp.gmail.com"
#define SMTP_PORT 465
//#define AUTHOR_EMAIL "lucestfm@gmail.com"
#define AUTHOR_PASSWORD "marypink"

/* Recipient's email*/
//#define RECIPIENT_EMAIL "lucestfm@gmail.com"

#endif // END CONFIG_H
