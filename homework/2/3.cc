//Purpose: Calculate the product of input integers and print out.
//Author: SiAce
//Date: 3/7/2017

#include <iostream>

using namespace std;

int main(){
  int product(1), value(0);
  while (cin >> value){
    product *= value;
  }
  cout << "The product is " << product << endl;
  return 0;
}
