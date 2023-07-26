#include <DFRobotDFPlayerMini.h>
#include <SoftwareSerial.h>
#include "Arduino.h"

#include "Sound.h"

SoftwareSerial daSerial(10, 11); // RX, TX
DFRobotDFPlayerMini player;

int track;

void Sound::PlaySound(String colour){

  //If blocks choose which sound plays
  
  if (colour == "RED") track = 1;
  else if (colour == "ORANGE") track = 2;
  else if (colour == "YELLOW") track = 3;
  else if (colour == "GREEN") track = 4;
  else if (colour == "BLUE") track = 5;
  else if (colour == "NAVY") track = 6;
  else if (colour == "PURPLE") track = 7;
  else track = 0;

  if(track != 0) player.play(track);

  delay(2000);
}

void Sound::StartPlayer(){

  //Wake the module

  daSerial.begin(9600);

  if (!player.begin(daSerial)) {
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1. Please recheck the connection!"));
    Serial.println(F("2. Insert the SD card!"));
    while (true);
  }

  player.volume(30);
}