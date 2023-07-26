#include <Wire.h>
#include <Adafruit_TCS34725.h>
#include <SoftwareSerial.h>
#include "HardwareSerial.h"
#include "WString.h"
#include "Colour.h"

#define GAIN_VALUE TCS34725_GAIN_4X
#define INTEGRATION_TIME_VALUE TCS34725_INTEGRATIONTIME_24MS

Adafruit_TCS34725 tcs;

String Colour::ReadColour(){
  
  //Read the value of red, green and blue from the sensor

  uint16_t r, g, b, c;
  tcs.getRawData(&r, &g, &b, &c);
  
  return NameColour(r, g, b);
}

String Colour::NameColour(int r, int g, int b){

  //If blocks return a name string form one of our 7 colours and they sets the sens range for the sensor

  if (r >= 500) {
    
    if(r < 1100 && r >= 850 && g < 200 && g >= 100 && b < 200 && b >= 100) return "RED";
    else if (r >= 750 && r < 1150 && g >= 200 && g < 300 && b >= 200 && b < 300 ) return "ORANGE";
    else if (r >= 1200 && r < 1800 && g < 1300 && g >= 300 && b >= 300 && b < 600) return "YELLOW";
    else return "X";

  } else if (r < 500) {
    
    if(r >= 85 && r < 200 && g < 375 && g >= 200 && b < 250) return "GREEN";
    else if (r < 300 && r >= 150 && g >= 225 && g < 375 && b >= 275 && b < 400 ) return "BLUE";
    else if(r < 175 && g < 150 && g >= 75 && b < 175 && b >= 100) return "NAVY";
    else if(r < 375 && r >= 200 && g < 175 && g >= 100 && b < 200 && b >= 125) return "PURPLE";
    else return "X";
  }
}

void Colour::StartColor(){

  //Wake the sensor

  tcs = Adafruit_TCS34725(INTEGRATION_TIME_VALUE, GAIN_VALUE);

  if (tcs.begin()) {
    Serial.println("Found sensor");
  } else {
    Serial.println("No TCS34725 found ... check your connections");
    while (true);
  }
}