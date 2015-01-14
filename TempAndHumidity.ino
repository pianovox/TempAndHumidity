#include <EEPROM.h>
#include "EEPROMAnything.h"
#include <elapsedMillis.h>
#include <dht.h>

#define dht_dpin A0 //no ; here. Set equal to channel sensor is on
dht DHT;



float hiTemp = 0; 
float loTemp = 100;

float loHumid = 100;
float hiHumid = 0;

elapsedMillis timeElapsed; //declare global if you don't want it reset every time loop runs
unsigned long hiTimeStampMs;
unsigned long loTimeStampMs;
unsigned long hiHumidStampMs;
unsigned long loHumidStampMs;
unsigned long ms;

//store the WHEN
int allTimeHiTempTime;
int allTimeLoTempTime;

int allTimeHiHumidTime;
int allTimeLoHumidTime;

//store the TEMPS as these variables
float allTimeHiTemp;
float allTimeLoTemp;

float allTimeHiHumid;
float allTimeLoHumid;

//where to save them
int hiTempAddy = 0;  //this works as long as numbers are under a byte (0-511)
int hiTimeAddy = 4;  //left space just in case.  Also use EPROMAnything if numbers get big (time?)

int loTempAddy = 10;
int loTimeAddy = 14;

int hiHumidAddy = 20;
int hiHumidTimeAddy = 24;

int loHumidAddy = 30;
int loHumidTimeAddy = 34;

//WriteANYTHING EePROM returns these valuse

int EEPROMreturn;

//keep track of saves
int saves = 0; //Resets when initialized

int resetButton;

void setup(){
  Serial.begin(9600);

  delay(300);//Let system settle
  delay(800);      //Wait rest of 1000ms recommended delay before
  //accessing sensor
  pinMode(2,INPUT);

}

void loop(){

  
  int resetButton = digitalRead(2); //RESET BUTTON

  myResetButton();
  Serial.println(resetButton);

  DHT.read11(dht_dpin);

  float newHiTempF = (DHT.temperature * 1.8) + 32;
  float newLoTempF = (DHT.temperature * 1.8) + 32;
  float newLoHumid = DHT.humidity;
  float newHiHumid = DHT.humidity;

  //KEEP TRACK OF HIGHS AND LOWS
  
//  EEPROM_writeAnything(0, b);
//EEPROM_writeAnything(2, b);
//EEPROM_writeAnything(4, c);
//=========================================================================

  if (newHiTempF > hiTemp){ //High Temp
    hiTemp = newHiTempF; 
    hiTimeStampMs = timeElapsed;
    allTimeHiTempTime = timeElapsed-hiTimeStampMs;
    allTimeHiTemp = (int)hiTemp;
    EEPROM.write(hiTempAddy,allTimeHiTemp);
    EEPROM_writeAnything(hiTimeAddy,allTimeHiTempTime);
    saves++;
  }
  
//==========================================================================  
  if (newLoTempF < loTemp){
    loTemp = newLoTempF; 
    loTimeStampMs = timeElapsed;
    allTimeLoTempTime = convertToHours(timeElapsed-loTimeStampMs);
    allTimeLoTemp = (int)loTemp;
    EEPROM.write(loTempAddy,allTimeLoTemp);
    EEPROM.write(loTimeAddy,allTimeLoTempTime);
    saves++;
  }
  if (newHiHumid > hiHumid){
    hiHumid = newHiHumid; 
    hiHumidStampMs = timeElapsed;
    allTimeHiHumidTime = convertToHours(timeElapsed-loTimeStampMs);
    allTimeHiHumid = (int)hiHumid;
    EEPROM.write(hiHumidAddy,allTimeHiHumid);
    EEPROM.write(hiHumidTimeAddy,allTimeHiHumidTime);
    saves++;
  }
  if (newLoHumid < loHumid){
    loHumid = newLoHumid; 
    loHumidStampMs = timeElapsed;
    allTimeLoHumidTime = convertToHours(timeElapsed-loTimeStampMs);
    allTimeLoHumid = (int)hiHumid;
    EEPROM.write(loHumidAddy,allTimeLoHumid);
    EEPROM.write(loHumidTimeAddy,allTimeLoHumidTime);
    saves++;
  }

  printCurrent();

  //  printHistory();
  printSavedHistory();
  Serial.print("saves so far ");
  Serial.print(saves);
  Serial.print("\n\n");

  //  std::cout << typeid(myVar).name();
  //SERIAL TERMAINAL COMMANDS
  //         /dev/tty.usbmodemfd121
  //         screen /dev/tty.usbmodemfd121 9600



  delay(5000); //but seems to work after 0.8 second.


  //RESET THE TIMER?
  //  if (convertToHours(timeElapsed) >= 168){
  //    timeElapsed = 0;
  //  }


}

























