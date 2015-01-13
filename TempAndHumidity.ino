#include <EEPROM.h>

#include <elapsedMillis.h>
#include <dht.h>
#define dht_dpin A0 //no ; here. Set equal to channel sensor is on
dht DHT;

elapsedMillis timeElapsed; //declare global if you don't want it reset every time loop runs
unsigned long hiTimeStampMs;
unsigned long loTimeStampMs;
unsigned long hiHumidStampMs;
unsigned long loHumidStampMs;

float hiTemp = 0.f;
float loTemp = 212.f;
float loHumid = 100.f;
float hiHumid = 0.f;

//store the hours
int allTimeHiTempTime;
int allTimeLoTempTime;
int allTimeHiHumidTime;
int allTimeLoHumidTime;

//store the temperatures
int allTimeHiTemp;
int allTimeLoTemp;
int allTimeHiHumid;
int allTimeLoHumid;

//where to save them
int hiTempAddy = 0;
int hiTimeAddy = 4;

int loTempAddy = 10;
int loTimeAddy = 14;

int hiHumidAddy = 20;
int hiHumidTimeAddy = 24;

int loHumidAddy = 30;
int loHumidTimeAddy = 34;

unsigned long ms;

void setup(){
  Serial.begin(9600);
  delay(300);//Let system settle
  delay(800);//Wait rest of 1000ms recommended delay before
  //accessing sensor
}

void loop(){
  DHT.read11(dht_dpin);
  float newHiTempF = ((DHT.temperature * 1.8) + 32);
  float newLoTempF = (DHT.temperature * 1.8) + 32;
  float newLoHumid = DHT.humidity;
  float newHiHumid = DHT.humidity;

  //KEEP TRACK OF HIGHS AND LOWS

  if (newHiTempF > hiTemp){ //High Temp
    hiTemp = newHiTempF; 
    hiTimeStampMs = timeElapsed;

    allTimeHiTempTime = convertToHours(timeElapsed-loTimeStampMs);
    allTimeHiTemp = (int)hiTemp;

    EEPROM.write(hiTempAddy,allTimeHiTemp);
    EEPROM.write(hiTimeAddy,allTimeHiTempTime);

  }
  if (newLoTempF < loTemp){
    loTemp = newLoTempF; 
    loTimeStampMs = timeElapsed;

    allTimeLoTempTime = convertToHours(timeElapsed-loTimeStampMs);
    allTimeLoTemp = (int)loTemp;

    EEPROM.write(loTempAddy,allTimeLoTemp);
    EEPROM.write(loTimeAddy,allTimeLoTempTime);

  }

  if (newHiHumid > hiHumid){
    hiHumid = newHiHumid; 
    hiHumidStampMs = timeElapsed;

    allTimeHiHumidTime = convertToHours(timeElapsed-loTimeStampMs);
    allTimeHiHumid = (int)hiHumid;


    EEPROM.write(hiHumidAddy,allTimeHiHumid);
    EEPROM.write(hiHumidTimeAddy,allTimeHiHumidTime);

  }
  if (newLoHumid < loHumid){
    loHumid = newLoHumid; 
    loHumidStampMs = timeElapsed;

    allTimeLoHumidTime = convertToHours(timeElapsed-loTimeStampMs);
    allTimeLoHumid = (int)hiHumid;


    EEPROM.write(loHumidAddy,allTimeLoHumid);
    EEPROM.write(loHumidTimeAddy,allTimeLoHumidTime);

  }

  //Print Time
  //  Serial.print("The current timestamp is:  ");
  //  WriteTime(timeElapsed);
  //  Serial.print("\n");  

  printCurrent();
//  printHistory();

  //  Serial.println(EEPROM.read(hiAddy));
  printSavedHistory();


  //  std::cout << typeid(myVar).name();
  //SERIAL TERMAINAL COMMANDS
  //         /dev/tty.usbmodemfd121
  //         screen /dev/tty.usbmodemfd121 9600



  delay(5000); //but seems to work after 0.8 second.

}













