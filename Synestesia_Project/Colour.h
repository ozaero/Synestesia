#include "WString.h"
#ifndef Colour_h
#define Colour_h

class Colour {
  
  public:
  
  void StartColor();
  String ReadColour();
  String NameColour(int r, int g, int b);
};

#endif