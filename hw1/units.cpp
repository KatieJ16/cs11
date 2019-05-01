#include "units.h"
using namespace std;

#include <iostream>
#include <string>


//Constructor
UValue::UValue(double value, string units) {
  this->value = value;
  this->units = units;
}
// Cleans up a UValue object.
UValue::~UValue() {
// No dynamically allocated resources; nothing to do!
}

// Returns value
double UValue::get_value(){
  return value;
}
// Returns units
string UValue::get_units(){
  return units;
}


UValue convert_to(UValue input, string to_units){

  //Convert for certain units
  if(input.get_units() == "lb" && to_units == "kg"){
    return UValue{input.get_value() * 0.45, to_units};
  }

  if(input.get_units() == "gal" && to_units == "L"){
    return UValue{input.get_value() * 3.79, to_units};
  }

  if(input.get_units() == "mi" && to_units == "km"){
    return UValue{input.get_value() * 1.6, to_units};
  }

  //return the same thing if it doesn't recognize the unit type
  return input;
}
