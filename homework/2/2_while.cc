//Purpose: Calculate the sum from integer 25 to 93.
//Author: SiAce
//Date: 3/7/2017

#include <iostream>

using namespace std;

int main(){
  int i(25),sum(0);
  while (i <= 93){
    sum += i;
    i++;
  }
  cout << "The sum from integer 25 to 93 is " << sum << endl;
  return 0;
}
  
  
