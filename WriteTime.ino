  void WriteTime(unsigned long ms){
  
  Serial.print(convertToHours(ms));
  Serial.print(": "); 
  Serial.print(convertToMinutes(ms));
  Serial.print(": "); 
  Serial.print(convertToSeconds(ms));
  Serial.print("\n");
}
