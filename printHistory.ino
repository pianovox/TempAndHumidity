void printHistory(){
  
  //Print History
  Serial.print("highest recorded temp:    ");
  Serial.print(hiTemp); 
  Serial.print("    "); 
  WriteTime(timeElapsed-hiTimeStampMs);
  //Serial.print(" ago. ");
  Serial.print("\n");  

  Serial.print("lowest recorded temp:     ");
  Serial.print(loTemp); 
  Serial.print("    "); 
  WriteTime(timeElapsed-loTimeStampMs);
  //  Serial.print(" ago. ");
  Serial.print("\n");  

  Serial.print("higest recorded humidity: ");
  Serial.print(hiHumid);
  Serial.print("    "); 
  WriteTime(timeElapsed-hiHumidStampMs);  
  //  Serial.print(" ago. ");
  Serial.print("\n");  

  Serial.print("lowest recorded humidity: ");
  Serial.print(loHumid);
  Serial.print("    "); 
  WriteTime(timeElapsed-loHumidStampMs);  
  //  Serial.print(" ago. ");
  Serial.print("\n\n\n");  

}
