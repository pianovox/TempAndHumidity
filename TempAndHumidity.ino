#include <EEPROM.h>
#include "EEPROMAnything.h"
#include <elapsedMillis.h>
#include <dht.h>
#define dht_dpin A0 //no ; here. Set equal to channel sensor is on
dht DHT;

int freq = 30000;          // how often should we be polling the sensor?

float hiTemp = 0; 
float loTemp = 100;
float loHumid = 100;
float hiHumid = 0;

float newHiTempF;
float newLoTempF;
float newLoHumid;
float newHiHumid;

elapsedMillis timeElapsed; // declare global if you don't want it reset every time loop runs
unsigned long pollingDelay1;
unsigned long pollingDelay2;
unsigned long hiTimeStampMs;
unsigned long loTimeStampMs;
unsigned long hiHumidStampMs;
unsigned long loHumidStampMs;
unsigned long ms;

unsigned long allTimeHiTempTime;  // store the WHEN
unsigned long allTimeLoTempTime;
unsigned long allTimeHiHumidTime;
unsigned long allTimeLoHumidTime;

float allTimeHiTemp;  // store the TEMPS as these variables
float allTimeLoTemp;
float allTimeHiHumid;
float allTimeLoHumid;

int hiTempAddy = 0;    // where to save them
int hiTimeAddy = 4;    // this works as long as numbers are under a byte (0-511)
int loTempAddy = 10;   // left space just in case.  Also use EPROMAnything if numbers get big (time?)
int loTimeAddy = 14;
int hiHumidAddy = 20;
int hiHumidTimeAddy = 24;
int loHumidAddy = 30;
int loHumidTimeAddy = 34;

unsigned long EEPROMreturnHiTempTime;  // WriteANYTHING EePROM returns these valuse
unsigned long EEPROMreturnLoTempTime;
unsigned long EEPROMreturnHiHumidTime;
unsigned long EEPROMreturnLoHumidTime;

int saves = 0; // keep track of saves - Resets when initialized
int resetButton;
//volatile int resetMe = LOW;   // necessary declaration for passing adjusting global variables with interrupts

//================================================================

void setup(){
  Serial.begin(9600);
  delay(300);    // Let system settle
  delay(800);    // Wait rest of 1000ms recommended delay before accessing sensor
  pinMode(2,INPUT);
  //  attachInterrupt(0, myResetButton, HIGH);    // attaches interrupt to Digital 2 with internal pull-up resistor
}

//================================================================

void loop(){
  int resetButton = digitalRead(2); // RESET BUTTON
  if (timeElapsed - pollingDelay1 > freq){
    readDHT();
    saveHiLo();
    printCurrent();

    Serial.print("   saves so far ");
    Serial.println(saves);

    printSavedHistory();

    pollingDelay1 = timeElapsed;
  }
  if (resetButton == 1){
    delay(10);
    if (resetButton == 1){
      hiTemp = 0;
      loTemp = 100;
      hiHumid = 0;
      loHumid = 100;
      saves = 0;
      Serial.println("HEY!!!! Who turned out the lights!?!");
    }
  }
  if (convertToHours(timeElapsed) >= 168){    //RESET THE TIMER?
    timeElapsed = 0;
  }
}

