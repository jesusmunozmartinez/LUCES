//************************************************************
// Author: Jesús Muñoz Martínez
// Proyect: LUCES.
// Trabajo Fin de Master. 
// Master de Sistemas Electrónicos para Entornos Inteligentes
//
// 1. blinks led once for every node on the mesh
// 2. blink cycle repeats every BLINK_PERIOD
// 3. sends a silly message to every node on the mesh at a random time between 1 and 5 seconds
// 4. prints anything it receives to Serial.print
// 5. OTA support and can be updated remotely
// 6. Support for BH1750 luminosity sensor  
// 7. Support for PIR sensor
// 8. Support for ACS712T
// 9. LittleFS for save configuration file
// 10. Control LED driver with PWM signal (0-10 by hardware)
//************************************************************

#include "painlessMesh.h"
#include <Arduino_JSON.h>
#include <wire.h>

#include "config.h"                 //configuration file
#include "mesh.h"
#include "readSensors.h"
#include "configFile.h"
#include "controlLum.h"
#include "utils.h"


JSONVar       config;
Scheduler     userScheduler; // to control task
painlessMesh  mesh;


bool onStatus = false;
bool onPresence = false;
int bright = 100;    // bright level [0..100].
int luxes = 0;


// Task Handlers, constructor

Task taskSendStatus( TASK_SECOND * 1, TASK_FOREVER, &sendMessageStatus );  //start with 5 second interval
Task taskControlLum( TASK_SECOND * 1, TASK_FOREVER, &controlLum );  //start with 1 second interval
Task taskBlinkNoNodes;

bool onFlag = false;


//  ----------------- SETUP -------------------------------- 

void setup() {

  pinMode(LED, OUTPUT);
  pinMode(PIRpin, INPUT);
  pinMode(A0, INPUT);
  pinMode(PWM, OUTPUT);
  pinMode(ZC, INPUT);
  pinMode(TRIAC, OUTPUT);

  Serial.begin(115200);
  printFwVersion();
  initFS();
  Wire.begin();  //I2C BUS

  initBH1750();
  loadConfig();
  initMesh();

   
  // Task blink Nodes
  taskBlinkNoNodes.set(BLINK_PERIOD, (mesh.getNodeList().size() + 1) * 2, []() {
      // If on, switch off, else switch on
      if (onFlag)
        onFlag = false;
      else
        onFlag = true;
      taskBlinkNoNodes.delay(BLINK_DURATION);

      if (taskBlinkNoNodes.isLastIteration()) {
        // Finished blinking. Reset task for next run 
        // blink number of nodes (including this node) times
        taskBlinkNoNodes.setIterations((mesh.getNodeList().size() + 1) * 2);
        // Calculate delay based on current mesh time and BLINK_PERIOD
        // This results in blinks between nodes being synced
        taskBlinkNoNodes.enableDelayed(BLINK_PERIOD - 
            (mesh.getNodeTime() % (BLINK_PERIOD*1000))/1000);
      }
  });

  userScheduler.addTask(taskBlinkNoNodes);
  taskBlinkNoNodes.enable();

  // Task Send Status 
  userScheduler.addTask(taskSendStatus);
  taskSendStatus.enable();

  // Task Control luminosity 
  userScheduler.addTask(taskControlLum);
  taskControlLum.enable();
 
  randomSeed(analogRead(A0));
}

//   -------------- Loop ----------------------- 
void loop() {  
  updateMesh();
  digitalWrite(LED, !onFlag);
}