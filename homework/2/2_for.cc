//Purpose: Calculate the sum from integer 25 to 93.
//Author: SiAce
//Date: 3/7/2017

#include <iostream>

using namespace std;

int main(){
  int i(0),sum(0);
  for (i=25;i<=93;i++)
    sum += i;
  cout << "The sum from integer 25 to 93 is " << sum << endl;
  return 0;
}
