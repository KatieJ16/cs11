
// read in needed things
using namespace std;
#include "units.h"
#include <iostream>
#include <string>


//add all the needed conversions
UnitConverter init_converter(){
  UnitConverter conversion;

  //Add all the conversions
  conversion.add_conversion("mi", 5280, "ft");
  conversion.add_conversion("mi", 1.6, "km");
  conversion.add_conversion("ft", 12, "in");
  conversion.add_conversion("in", 2.54, "cm");
  conversion.add_conversion("lb", 0.45, "kg");
  conversion.add_conversion("stone", 14, "lb");
  conversion.add_conversion("lb", 16, "oz");
  conversion.add_conversion("kg", 1000, "g");
  conversion.add_conversion("gal", 3.79, "L");
  conversion.add_conversion("bushel", 9.3, "gal");
  conversion.add_conversion("ft^3", 7.5, "gal");
  conversion.add_conversion("L", 1000, "ml");

  //return list of conversions
  return conversion;

}

// main loop of code
int main(){

  //make list of conversions
  UnitConverter u = init_converter();

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


  //Convert and print
  try{
    UValue output = u.convert_to(input, to_units);
    cout << "Converted to: " << output.get_value() << " " << output.get_units() << "\n";
  }
  catch(int e){ //when you can't convert
    cout << "Couldn't convert to " << to_units <<"!\n";

  }

  return 0;
}
