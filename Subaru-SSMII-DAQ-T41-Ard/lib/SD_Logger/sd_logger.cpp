#include <Arduino.h>
#include <config.h>

#include <sd_logger.h>

/*************************************************************************
 * INSTATIATION DEFINITIONS
**************************************************************************/
File logFile;


/*************************************************************************
 * FUNCTIONS
**************************************************************************/

// initializes the sd logger
bool loggerBegin(){
  #ifdef DEBUG
    if (!SD.begin(chipSelect)) {
      Serial.println("SD initialization failed!");
    }
    else
      Serial.println("SD Initialized");
  #endif

  // CORRECT THE FILE NAME
  logFile = SD.open("newlog.CSV", FILE_WRITE);
   
  #ifdef DEBUG
    if(logFile)
      Serial.println("File opened");
    else
      Serial.println("File open failed");
  #endif

  outputHeaders(logFile);
  logFile.flush();

  return true;
}

// outputs data column headers to the specified stream (serial, file, etc.)
void outputHeaders(Stream &outStream){
  outStream.println("RPM\tSpeed\tTPS\tMAP\tTiming\tECT\tIAT\tEFT\tVoltage");
}