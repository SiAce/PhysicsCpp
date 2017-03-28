#include <iostream>

using namespace std;

int main() {
  string out,line;
  while (getline(cin,line)){
    for (auto c : line){
      if (isalnum(c))
	out += c;
    }
    cout << out << endl;
  }
  
  return 0;
}
