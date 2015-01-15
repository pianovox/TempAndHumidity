void saveHiLo(){
  if (newHiTempF > hiTemp){ //High Temp
    hiTemp = newHiTempF; 
    hiTimeStampMs = timeElapsed;
    allTimeHiTempTime = hiTimeStampMs;
    allTimeHiTemp = (int)hiTemp;
    EEPROM.write(hiTempAddy,allTimeHiTemp);
    EEPROM_writeAnything(hiTimeAddy,allTimeHiTempTime);
    saves++;
  }
  if (newLoTempF < loTemp){
    loTemp = newLoTempF; 
    loTimeStampMs = timeElapsed;
    allTimeLoTempTime = convertToHours(timeElapsed-loTimeStampMs);
    allTimeLoTemp = (int)loTemp;
    EEPROM.write(loTempAddy,allTimeLoTemp);
    EEPROM.write(loTimeAddy,allTimeLoTempTime);
    saves++;
  }
  if (newHiHumid > hiHumid){
    hiHumid = newHiHumid; 
    hiHumidStampMs = timeElapsed;
    allTimeHiHumidTime = convertToHours(timeElapsed-loTimeStampMs);
    allTimeHiHumid = (int)hiHumid;
    EEPROM.write(hiHumidAddy,allTimeHiHumid);
    EEPROM.write(hiHumidTimeAddy,allTimeHiHumidTime);
    saves++;
  }
  if (newLoHumid < loHumid){
    loHumid = newLoHumid; 
    loHumidStampMs = timeElapsed;
    allTimeLoHumidTime = convertToHours(timeElapsed-loTimeStampMs);
    allTimeLoHumid = (int)hiHumid;
    EEPROM.write(loHumidAddy,allTimeLoHumid);
    EEPROM.write(loHumidTimeAddy,allTimeLoHumidTime);
    saves++;
  }
}

