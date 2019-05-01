
// read in needed things
using namespace std;
#include "units.h"
#include <iostream>
#include <string>

// main loop of code
int main(){

  //get input values
  double value;
  string units;
  cout << "Enter value with units: ";
  cin >> value >> units;

  //get units to convert to
  string to_units;
  cout << "Covert to units: ";
  cin >> to_units;

  UValue input = {value, units};


  //Convert
  UValue converted = convert_to(input, to_units);

  //print only if it worked
  if(converted.get_value() == value){
    cout << "Couldn't convert to " << to_units <<"!\n";
  } else {
    cout << "Converted to: " << converted.get_value() << " " << converted.get_units() << "\n";

  }

  return 0;
}
