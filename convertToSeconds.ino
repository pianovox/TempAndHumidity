  unsigned long convertToSeconds(unsigned long ms) {
  unsigned long seconds = (ms/1000) % 60;
  unsigned long minutes = seconds /60; 
  unsigned long hours = minutes/60;

  return seconds;
}
