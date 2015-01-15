void WriteTime(unsigned long ms){  //WRITE THE TIME IN HH:MM:SS
  Serial.print(convertToHours(ms));
  Serial.print(": "); 
  Serial.print(convertToMinutes(ms));
  Serial.print(": "); 
  Serial.print(convertToSeconds(ms));
  Serial.print("\n");
}
unsigned long convertToHours(unsigned long ms) {  //Hours
  unsigned long seconds = ms/1000;
  unsigned long minutes = seconds /60; 
  unsigned long hours = minutes/60;
  return (int) hours;
}
unsigned long convertToMinutes(unsigned long ms) {  //Minutes
  unsigned long seconds = ms/1000;
  unsigned long minutes = seconds /60; 
  unsigned long hours = minutes/60;
  return (int) minutes;
}
unsigned long convertToSeconds(unsigned long ms) {  //Seconds
  unsigned long seconds = (ms/1000) % 60;
  unsigned long minutes = seconds /60; 
  unsigned long hours = minutes/60;
  return (int) seconds;
}


