void readDHT(){
  DHT.read11(dht_dpin);

  newHiTempF = (DHT.temperature * 1.8) + 32;
  newLoTempF = (DHT.temperature * 1.8) + 32;
  newLoHumid = DHT.humidity;
  newHiHumid = DHT.humidity;
}

