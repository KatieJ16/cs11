using namespace std;
#include <string>
#include <vector>
#include <set>

// Class that stores the rational number
class Rational {
  private:
    int n; // Numerator of the rational number
    int d; // Denominator of the ratinal number
    int gcd(int a,int b); // find the greatest common denominator between two integers

  public:
     // Constructor
     Rational();
     Rational(int n);
     Rational(int n, int d);
     ~Rational(); // Destructor
     //Accessors
     int num() const; //returns the numerator
     int denom() const; //returns the denominator

     Rational reciprocal(); //returns the reciprocal of this number
     int reduce(); //reduces the fraction

     //redefine operators
     Rational & operator+=(const Rational &num2);
     Rational & operator-=(const Rational &num2);
     Rational & operator*=(const Rational &num2);
     Rational & operator/=(const Rational &num2);

     friend ostream & operator << (ostream &out, const Rational &num);
};

//redefine operators
Rational operator+(const Rational &num1, const Rational &num2);
Rational operator-(const Rational &num1, const Rational &num2);
Rational operator*(const Rational &num1, const Rational &num2);
Rational operator/(const Rational &num1, const Rational &num2);
