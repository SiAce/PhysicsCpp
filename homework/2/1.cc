//Purpose: Calculate the production of two integer.
//Author: SiAce
//Date: 3/7/2017

#include <iostream>

using namespace std;

int main () {
  int a(0),b(0),c(0);
  cout << "Enter two numbers:" << endl;
  cin >> a >> b;
  c = a * b;
  cout << "The production of " << a << " and "
       << b << " is " << c << endl;
  return 0;
}
