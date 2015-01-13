void printSavedHistory(){

  //Print History
  Serial.print("highest recorded temp (saved):        ");
  Serial.print(EEPROM.read(hiTempAddy)); 
  Serial.print("    "); 
  Serial.println(EEPROM.read(hiTimeAddy));  //Serial.print(" ago. ");

  Serial.print("lowest recorded temp (saved):         ");
  Serial.print(EEPROM.read(loTempAddy)); 
  Serial.print("    "); 
  Serial.println(EEPROM.read(loTimeAddy));  //Serial.print(" ago. ");

  Serial.print("highest recorded humidity (saved):    ");
  Serial.print(EEPROM.read(hiHumidAddy)); 
  Serial.print("    "); 
  Serial.println(EEPROM.read(hiHumidTimeAddy));  //Serial.print(" ago. ");

  Serial.print("lowest recorded humidity (saved):     ");
  Serial.print(EEPROM.read(loHumidAddy)); 
  Serial.print("    "); 
  Serial.println(EEPROM.read(loHumidTimeAddy));  //Serial.print(" ago. ");
  Serial.print("\n");  


}

