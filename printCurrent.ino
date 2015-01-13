void printCurrent(){
 
  Serial.print("Current humidity = ");
  Serial.print(DHT.humidity);
  Serial.print("%       ");
  Serial.print("temperature = ");
  Serial.print((DHT.temperature * 1.8) + 32);
  Serial.println("F  ");
}
