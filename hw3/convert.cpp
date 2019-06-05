
// read in needed things
using namespace std;
#include "units.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include <set>


//add all the needed conversions
UnitConverter init_converter(){
  UnitConverter conversion;

  //open file to read and throw exception if it doesn't work
  ifstream ifs{"rules.txt"};

  if(!ifs)
    throw std::invalid_argument("Couldn't open file");

  //read in data if file loaded
  while(ifs) {
    //read in data
    string from_units;
    double multiplier;
    string to_units;
    ifs >> from_units;
    ifs >> multiplier;
    ifs >> to_units;

    //add conversion
    conversion.add_conversion(from_units, multiplier, to_units);
  }

  //return list of conversions
  return conversion;

}

// main loop of code
int main(){

  UnitConverter u;
  //make list of conversions
  try{
    u = init_converter();
  }
  catch(int e){
    return 1;
  }
  //get input values
  double value;
  string units;
  cout << "Enter value with units: ";
  cin >> value >> units;

  //get units to convert to
  string to_units;
  cout << "Covert to units: ";
  cin >> to_units;

  UValue input = UValue(value, units);


  //Convert and print
  try{
    std::set<string> seen;
    UValue output = u.convert_to(input, to_units, seen);
    cout << "Converted to: " << output.get_value() << " " << output.get_units() << "\n";
  }
  catch (const std::invalid_argument& ia){ //when you can't convert
    cout << "Couldn't convert to " << to_units <<"!\n";
    return 1;
  }

  return 0;
}
