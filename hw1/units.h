using namespace std;
#include <string>

// Class for values wit units
class UValue {
  private:
    double value; //the value (number) of the measurement
    string units; // the units of the measurement

  public:
     // Constructor
    UValue(double value, string units);
    ~UValue(); // Destructor
    double get_value(); // Accessors
    string get_units();
};

UValue convert_to(UValue input, string to_units);
