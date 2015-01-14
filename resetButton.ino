void myResetButton(){
  if (resetButton = HIGH){
    delay(10);
    if (resetButton = HIGH){
      allTimeHiTemp = DHT.temperature;
      allTimeLoTemp = DHT.temperature;
      allTimeLoHumid = DHT.humidity;
      allTimeHiHumid = DHT.humidity;
    }
  }
}


