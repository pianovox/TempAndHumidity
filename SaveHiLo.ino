void saveHiLo(){
  if (newHiTempF > hiTemp){ //High Temp
    hiTemp = newHiTempF; 
    hiTimeStampMs = timeElapsed;
    allTimeHiTempTime = hiTimeStampMs;
    allTimeHiTemp = (int)hiTemp;
    EEPROM.write(hiTempAddy,allTimeHiTemp);
    EEPROM_writeAnything(hiTimeAddy,allTimeHiTempTime);
    EEPROM_readAnything(hiTimeAddy,EEPROMreturnHiTempTime);

    saves++;
  }
  if (newLoTempF < loTemp){
    loTemp = newLoTempF; 
    loTimeStampMs = timeElapsed;
    allTimeLoTempTime = convertToHours(timeElapsed-loTimeStampMs);
    allTimeLoTemp = (int)loTemp;
    EEPROM.write(loTempAddy,allTimeLoTemp);
    EEPROM.write(loTimeAddy,allTimeLoTempTime);
    EEPROM_readAnything(loTimeAddy,EEPROMreturnLoTempTime);

    saves++;
  }
  if (newHiHumid > hiHumid){
    hiHumid = newHiHumid; 
    hiHumidStampMs = timeElapsed;
    allTimeHiHumidTime = convertToHours(timeElapsed-loTimeStampMs);
    allTimeHiHumid = (int)hiHumid;
    EEPROM.write(hiHumidAddy,allTimeHiHumid);
    EEPROM.write(hiHumidTimeAddy,allTimeHiHumidTime);
    EEPROM_readAnything(hiHumidTimeAddy,EEPROMreturnHiHumidTime);

    saves++;
  }
  if (newLoHumid < loHumid){
    loHumid = newLoHumid; 
    loHumidStampMs = timeElapsed;
    allTimeLoHumidTime = convertToHours(timeElapsed-loTimeStampMs);
    allTimeLoHumid = (int)hiHumid;
    EEPROM.write(loHumidAddy,allTimeLoHumid);
    EEPROM.write(loHumidTimeAddy,allTimeLoHumidTime);
    EEPROM_readAnything(hiHumidTimeAddy,EEPROMreturnLoHumidTime);

    saves++;
  }
}




