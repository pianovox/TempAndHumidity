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
  }
  if (newLoTempF < loTemp){
    loTemp = newLoTempF; 
    loTimeStampMs = timeElapsed;
  }
  if (newLoHumid < loHumid){
    loHumid = newLoHumid; 
    loHumidStampMs = timeElapsed;
  }
  if (newHiHumid > hiHumid){
    hiHumid = newHiHumid; 
    hiHumidStampMs = timeElapsed;
  }


  //Print Time
//  Serial.print("The current timestamp is:  ");
//  WriteTime(timeElapsed);
//  Serial.print("\n");  

  printCurrent();
  printHistory();


  //  std::cout << typeid(myVar).name();
  //SERIAL TERMAINAL COMMANDS
//         /dev/tty.usbmodemfd121
//         screen /dev/tty.usbmodemfd121 9600



  delay(5000); //but seems to work after 0.8 second.

}










