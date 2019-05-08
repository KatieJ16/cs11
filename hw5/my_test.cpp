#include "rational.h"
using namespace std;

#include <iostream>
#include <string>
#include <set>

// main loop of code
int main(){

  Rational num1{1, 2};

  Rational num2 = {1, 4};

  Rational added = num1 + num2;
  cout << "\n" << added.num() << "\n"<< added.denom()<<"\n";

  added = num1 - num2;
  cout << "\n" << added.num() << "\n"<< added.denom()<<"\n";

   added = num1 * num2;
  cout << "\n" << added.num() << "\n"<< added.denom()<<"\n";

   added = num1 / num2;
  cout << "\n" << added.num() << "\n"<< added.denom()<<"\n";

  added+= num1;
 cout << "\n" << added.num() << "\n"<< added.denom()<<"\n";

  return 0;
}
