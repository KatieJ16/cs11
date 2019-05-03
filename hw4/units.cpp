#include "units.h"
using namespace std;

#include <iostream>
#include <string>
#include <set>


/** Constructor */
UValue::UValue(double value, string units) {
  this->value = value;
  this->units = units;
}
/** Cleans up a UValue object.*/
UValue::~UValue() {
// No dynamically allocated resources; nothing to do!
}

/** Returns value */
double UValue::get_value() const{
  return value;
}
/** Returns units */
string UValue::get_units() const{
  return units;
}


void UnitConverter::add_conversion(const string &from_units, const double &multiplier, const string &to_units){
  /** adds a conversion units to the list*/

  //make the conversion unit
  Conversion this_one = {(string) from_units, (double) multiplier, (string) to_units};

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

UValue UnitConverter::convert_to(const UValue &input, const string &to_units, std::set<string> seen){
  /** converts from one unit to another, uses recursion to go from
  * units that we don't have direct convesions to
  */
  //check to see if we've seen this unit before
  if(input.get_units() == to_units){
    return input;
  }

  //add units to seen because we've seen this unit now
  seen.insert(input.get_units());

  double multiplier = 0.0; // this will store the multiplier function
  //find conversion
  //loop through all the entries
  for(int i = 0; (unsigned) i < conversions.size(); ++i){
    //if you can just convert, do so and return
    if(conversions[i].from_units ==  input.get_units()){
      if(conversions[i].to_units == (string) to_units){
        multiplier = conversions[i].multiplier;
        return UValue(input.get_value() * multiplier, to_units);
      }
    }
  }

  //when you can't just go there, convert to some step that you haven't been to yet
  //first find some new value to convert to
  for(int i = 0; (unsigned) i < conversions.size(); ++i){
    if(conversions[i].from_units ==  input.get_units()){
      string to_units_converted = conversions[i].to_units;
      //check if convert too
      if(seen.count(to_units_converted) == 0 ){
        //convert if you haven't seen that unit yet
        multiplier = conversions[i].multiplier;
        UValue new_input = UValue(input.get_value() * multiplier, to_units_converted);
        return convert_to(new_input, to_units, seen);
      }
    }
    //you just keep looping through the entries of conversion if you have already converted to that stage.
  }

  //When the desired conversion isn't stored, and you can't find a path to it
  if(multiplier == 0.0){
    string message = "Don't know how to convert from " + input.get_units() + " to " + to_units;
    throw invalid_argument(message);
  }

  return UValue{input.get_value() * multiplier, to_units};

}

UValue UnitConverter::convert_to(const UValue &v, const string &to_units) {
    /** start recursion for conversion */
    return convert_to(v, to_units, set<string>{});
}
