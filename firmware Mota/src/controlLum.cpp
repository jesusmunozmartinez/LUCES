//************************************************************
// Author: Jesús Muñoz Martínez
// Proyect: Trabajo Fin de Master: LUCES.
// Master de Sistemas Electrónicos para Entornos Inteligentes
// Mota Node.
// Description: Header file from controlLum.cpp
//
//************************************************************


/* Example message
msg={"type":"C","mode":"lumAmb","mOn":"Off","mLux":"39","mTon":"19:54","mToff":"06:53","lum":"time",
"bVal":"67","bT1":"20:37","bT2":"22:37","bT1Lux":"50","bT2Lux":"100","bT3Lux":"80","bPre":"52"}
*/


#include "controlLum.h"
#include "utils.h"
#include <TimeLib.h>


extern JSONVar config;
extern bool onPresence;
extern bool onStatus;
extern int bright;    // bright level [0..255] for getreadings
extern int brightNow; 
extern int luxes;
extern Task taskFadeLum;



void fadeLum(){
    if (bright > brightNow){
        brightNow++;
        //int value = map(brightNow, 0, 100, 0, 255);
        analogWrite(PWM, brightNow);
    }else if (bright < brightNow){
        brightNow--;
        //int value = map(brightNow, 0, 100, 0, 255);
        analogWrite(PWM, brightNow);
    }
}


void powerLum(){
    int value;
    if (!onPresence){
        value = atoi(config["bPre"]);
        bright = value;
    }else{ 
        if((strcmp(config["lum"],"time") == 0)){
            value = bright;
        }else{
            value = atoi(config["bVal"]);
            bright = value;
        }
    }
    if (bright == brightNow){
        taskFadeLum.disable();
    }else{
        taskFadeLum.enable();
    }
}



void parseTime(String str, int &hour, int &min  ){

    JSONVar jTime = config[str];
    String jTimeStr = JSON.stringify(jTime);
    hour = jTimeStr.substring(1,3).toInt();
    min = jTimeStr.substring(4,6).toInt();
}



bool timeOnRange(String str1, String str2){
    time_t tnow = now();
    int hnow= hour(tnow); 
    int mnow= minute(tnow);
    int hon, mon, hoff, moff; 
    parseTime(str1, hon, mon);  
    parseTime(str2, hoff, moff);  

    if (hon > hoff){ // time off is in the next day
        if (hnow > hon && hnow<=23){    
            return true;   
        }else if(hnow < hoff){
            return true;       
        }else if (hnow == hon && mnow >= mon){
            return true;
        }else if (hnow == hoff&&mnow <= moff){
            return true;
        }else{
            return false;
        }   
    }else{  // time off in the same day
        if (hnow > hon && hnow<hoff){
            return true;
        }else if (hnow == hon && mnow >= mon){
            return true;
        }else if (hnow == hoff&&mnow <= moff){
            return true;
        }else{
            return false;
        }
    }
}




void checkTimeRange(){
    if (timeOnRange("mTon","bT1")){
        bright = atoi(config["bT1Lux"]);
        //Serial.println("range1");
    }else if (timeOnRange("bT1","bT2")){
        bright = atoi(config["bT2Lux"]);
        //Serial.println("range2");
    }else if (timeOnRange("bT2","mToff")){
        bright = atoi(config["bT3Lux"]);
        //Serial.println("range3");
    } 
}



void controlLum(){
    if (strcmp(config["mode"], "manual") == 0) {
        //Serial.println("Modo manual");
        if (strcmp(config["mOn"], "on") == 0) {
            powerLum();
            onStatus = true;
        }else if (strcmp(config["mOn"], "off") == 0) {
            analogWrite(PWM, 0);
            onStatus = false;
            bright = 0;
            brightNow = 0;
        }
    }else if (strcmp(config["mode"], "lumAmb") == 0){
        int luxOnOff = atoi(config["mLux"]);
        if (luxes < luxOnOff){
            onStatus = true;
            if(strcmp(config["lum"], "manual") == 0){
               // Serial.println("Modo LumAmb, manual on");
                powerLum();
            }else{
               // Serial.println("Modo LumAmb, time");
                checkTimeRange();
                powerLum();
            }
        }else{
           // Serial.println("Modo LumAmb, off");
            analogWrite(PWM, 0);
            onStatus = false;
            bright = 0;
            brightNow = 0;
        }
    }else if (strcmp(config["mode"], "time") == 0){
          if (timeOnRange("mTon","mToff")){  
            onStatus = true;
            if(strcmp(config["lum"], "manual") == 0){
               // Serial.println("Modo Time, manual on");
                powerLum();
            }else{
               // Serial.println("Modo Time, time on");
                checkTimeRange();
                powerLum();
            }
        }else{
            //Serial.println("Modo Time, off");
            analogWrite(PWM, 0);
            onStatus = false;
            bright = 0;
            brightNow = 0;
        }
    }
}
