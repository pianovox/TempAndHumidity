void printSavedHistory(){

  //Print History
  Serial.print("highest recorded temp (saved):        ");
  Serial.print(EEPROM.read(hiTempAddy)); 
  Serial.print("    "); 
  WriteTime(EEPROM_readAnything(hiTimeAddy, EEPROMreturn));

  Serial.print("lowest recorded temp (saved):         ");
  Serial.print(EEPROM.read(loTempAddy)); 
  Serial.print("    "); 
  WriteTime(timeElapsed-EEPROM.read(loTimeAddy));

  Serial.print("highest recorded humidity (saved):    ");
  Serial.print(EEPROM.read(hiHumidAddy)); 
  Serial.print("    "); 
  Serial.println(EEPROM.read(hiHumidTimeAddy));

  Serial.print("lowest recorded humidity (saved):     ");
  Serial.print(EEPROM.read(loHumidAddy)); 
  Serial.print("    "); 
  Serial.println(EEPROM.read(loHumidTimeAddy));
  Serial.print("\n");  


}


