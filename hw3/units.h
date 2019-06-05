using namespace std;
#include <string>
#include <vector>
#include <set>

// Class for values wit units
class UValue {
  private:
    double value;
    string units;

  public:
     // Constructor
    UValue(double value, string units);
    ~UValue(); // Destructor
    double get_value() const; // Accessors
    string get_units() const;
};

//The new class for unit converter
class UnitConverter{
  private:
    //Make struct that will store info about each conversion
    struct Conversion{
      string from_units;
      double multiplier;
      string to_units;

    };

    //This will be the vector of all conversions
    vector<Conversion> conversions;

  public:
    void add_conversion(const string &from_units, const double &multiplier, const string &to_units);
    UValue convert_to(const UValue &input, const string &to_units, std::set<string> seen);
    UValue convert_to(const UValue &v, const string &to_units);

};
