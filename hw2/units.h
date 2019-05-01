using namespace std;
#include <string>
#include <vector>

// Class for values wit units
class UValue {
  private:
    double value; //where numerical value gets stored
    string units; //where name of units gets stored

  public:
     // Constructor
    UValue(double value, string units);
    ~UValue(); // Destructor
    double get_value(); // Accessors
    string get_units();
};

//The new class for unit converter
class UnitConverter{
  private:
    //Make struct that will store info about each conversion
    struct Conversion{
      string from_units; //the units that we start in
      double multiplier; //the factor we multiply by to change units approriately
      string to_units; // the units we want to convert to

    };

    //This will be the vector of all conversions
    vector<Conversion> conversions;

  public:
    void add_conversion(string from_units, double multiplier, string to_units);
    UValue convert_to(UValue input, string to_units);

};
