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


void UnitConverter::add_conversion(string from_units, double multiplier, string to_units){
  //make the conversion unit
  Conversion this_one = {from_units, multiplier, to_units};

  //check if the conversion is already there
  //loop through all the entries
  for(int i = 0; (unsigned) i < conversions.size(); ++i){
    //if its there, throw exception
    if((conversions[i].from_units == from_units) && (conversions[i].to_units == to_units)){
      string message = "Already have a conversion from " + from_units + " to " + to_units;
      throw invalid_argument(message);
    }
  }

  //if it's not there, then we will add it to the list
  conversions.push_back(this_one);

  //also add the opposite direction
  Conversion flipped = {to_units, 1/multiplier, from_units};
  conversions.push_back(flipped);
}

UValue UnitConverter::convert_to(UValue input, string to_units){
  double multiplier = 0.0; // this will store the multiplier function
  //find conversion
  //loop through all the entries
  for(int i = 0; (unsigned) i < conversions.size(); ++i){
    //if its there, throw exception
    if(conversions[i].from_units == input.get_units()){
      if(conversions[i].to_units == to_units){
        multiplier = conversions[i].multiplier;
        break;
      }
    }
  }

  //When the desired conversion isn't stored
  if(multiplier == 0.0){
    string message = "Don't know how to convert from " + input.get_units() + " to " + to_units;
    throw invalid_argument(message);
  }

  return UValue{input.get_value() * multiplier, to_units};

}
