#include "rational.h"
using namespace std;

#include <iostream>
#include <string>
#include <set>


//Constructors
Rational::Rational(){
  this->n = 0;
  this->d = 1;
}
Rational::Rational(int n){
  this->n = n;
  this->d = 1;
}
Rational::Rational(int n, int d){
  if(d == 0){ // the denominator cannot be zero
    throw std::invalid_argument("Denominator must not be 0.");
  }
  this->n = n;
  this->d = d;
}
// Cleans up a Rational object.
Rational::~Rational() {
// No dynamically allocated resources; nothing to do!
}

// Returns the numerator
int Rational::num() const{
  return n;
}
// Returns the denominator
int Rational::denom() const{
  return d;
}

//returns the reciprocal of this number
Rational Rational::reciprocal(){
  //only need to switch n and d
  Rational answer{d, n};
  return answer;
}

//find the greatest common denominator between two integers
int Rational::gcd(int a, int b){
  //will use the euclidean algorithm to recursively find the gcd

  //if one number is zero, return the other number
  if(a == 0){
    return b;
  }
  if(b == 0){
    return a;
  }

  //otherwise, write find the remainder of a/b
  int r = a % b; //r is remainder

  //now gcd(a,b) = gcd(b,r) and recursively repeat
  return gcd(b,r);

}

//will return a function
int Rational::reduce(){

  //if numerator is 0, then change to 0/1
  if(this->n == 0){
    this->n = 0;
    this->d = 1;
    return 0;
  }

  //get common denominator
  int factor = this->gcd(n, d);
  if(factor == 1){ // this is when we stop
    return 0;
  }
  //if it's not 1, then we divide by it
  n = n/factor;
  d = d/factor;

  //and repeat
  this->reduce();
  return 0;

}
Rational & Rational::operator+=(const Rational &num2){
  //first get common Denominator, by multiplying by denominator of other number
  Rational num1_common{n* num2.denom(), d * num2.denom()};
  Rational num2_common{num2.num() * d,  num2.denom() * n};

  //add numerators and keep denominator the same;
  n = num1_common.num() + num2_common.num();
  d = num1_common.denom();

  //reduce and return
  reduce();
  return *this;

}

Rational & Rational::operator-=(const Rational &num2){
  //first get common Denominator, by multiplying by denominator of other number
  Rational num1_common{n* num2.denom(), d * num2.denom()};
  Rational num2_common{num2.num() * d,  num2.denom() * n};

  //subract numerators and keep denominator the same;
  n = num1_common.num() - num2_common.num();
  d = num1_common.denom();

  //reduce and return
  reduce();
  return *this;

}

Rational & Rational::operator*=(const Rational &num2){
  //multiply tops and bottoms
  n *= num2.num();
  d *= num2.denom();

  //reduce and return
  reduce();
  return *this;

}

Rational & Rational::operator/=(const Rational &num2){
  //cross multiply
  n *= num2.denom();
  d *= num2.num();

  //reduce and return
  reduce();
  return *this;

}

Rational operator+(const Rational &num1, const Rational &num2){
  //first get common Denominator, by multiplying by denominator of other number
  Rational num1_common{num1.num() * num2.denom(), num1.denom() * num2.denom()};
  Rational num2_common{num2.num() * num1.denom(), num2.denom() * num1.denom()};

  //add numerators and keep denominator the same;
  Rational added{num1_common.num() + num2_common.num(), num1_common.denom()};

  //reduce and return
  added.reduce();
  return added;

}
Rational operator-(const Rational &num1, const Rational &num2){
  //first get common Denominator, by multiplying by denominator of other number
  Rational num1_common{num1.num() * num2.denom(), num1.denom() * num2.denom()};
  Rational num2_common{num2.num() * num1.denom(), num2.denom() * num1.denom()};

  //subtract numerators and keep denominator the same;
  Rational sub{num1_common.num() - num2_common.num(), num1_common.denom()};

  //reduce and return
  sub.reduce();
  return sub;
}
//multiply 2 rational numbers
Rational operator*(const Rational &num1, const Rational &num2){
  //multiply tops and bottoms
  Rational multiply{num1.num() * num2.num(), num1.denom() * num2.denom()};
  //reduce and return
  multiply.reduce();
  return multiply;

}
//divide two rational numbers
Rational operator/(const Rational &num1, const Rational &num2){
  //cross multiply
  Rational divide{num1.num() * num2.denom(), num1.denom() * num2.num()};
  //reduce and return
  divide.reduce();
  return divide;
}

ostream & operator << (ostream &out, const Rational &num)
{
    if(num.num() == 1){
      out << 1;
      return out;
    }
    if (num.num() == 0){
      out << 0;
      return out;
    }
    out << num.num() << "/" << num.denom();
    return out;
}
