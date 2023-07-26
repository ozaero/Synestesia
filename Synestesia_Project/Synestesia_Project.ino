#include "Colour.h"
#include "Sound.h"

Colour Colour;
Sound Sound;

String colour;

void setup(){

  Parameter();
  Sound.StartPlayer();
}

void loop(){

  //First read the colour after if there is a colour it is in the range of our colours. Than it lets play related sound

  colour = Colour.ReadColour();
  Sound.PlaySound(colour);
}

void Parameter(){

  Serial.begin(9600);

  //Wake the componenets

  Colour.StartColor();
  Sound.StartPlayer();
}