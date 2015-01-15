void printSavedHistory(){

  //Print History
  Serial.print("highest recorded temp (saved):        ");
  Serial.print(EEPROM.read(hiTempAddy)); 
  Serial.print("    "); 
  WriteTime(timeElapsed-EEPROMreturnHiTempTime);

  Serial.print("lowest recorded temp (saved):         ");
  Serial.print(EEPROM.read(loTempAddy)); 
  Serial.print("    "); 
  WriteTime(timeElapsed-EEPROMreturnLoTempTime);

  Serial.print("highest recorded humidity (saved):    ");
  Serial.print(EEPROM.read(hiHumidAddy)); 
  Serial.print("    "); 
  WriteTime(timeElapsed-EEPROMreturnHiHumidTime);

  Serial.print("lowest recorded humidity (saved):     ");
  Serial.print(EEPROM.read(loHumidAddy)); 
  Serial.print("    "); 
  WriteTime(timeElapsed-EEPROMreturnLoHumidTime);
  Serial.print("\n");  
}

void printHistory(){
  Serial.print("highest recorded temp:    ");
  Serial.print(hiTemp); 
  Serial.print("    "); 
  WriteTime(timeElapsed-hiTimeStampMs);
  Serial.print("\n");  

  Serial.print("lowest recorded temp:     ");
  Serial.print(loTemp); 
  Serial.print("    "); 
  WriteTime(timeElapsed-loTimeStampMs);
  Serial.print("\n");  

  Serial.print("higest recorded humidity: ");
  Serial.print(hiHumid);
  Serial.print("    "); 
  WriteTime(timeElapsed-hiHumidStampMs);  
  Serial.print("\n");  

  Serial.print("lowest recorded humidity: ");
  Serial.print(loHumid);
  Serial.print("    "); 
  WriteTime(timeElapsed-loHumidStampMs);  
  Serial.print("\n\n\n");  

}

void printCurrent(){
 
  Serial.print("        Current humidity = ");
  Serial.print(DHT.humidity);
  Serial.print("%       ");
  Serial.print("temperature = ");
  Serial.print((DHT.temperature * 1.8) + 32);
  Serial.println("F  ");
}
