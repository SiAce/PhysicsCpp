#include<iostream>
#include<sstream>
#include<string>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::vector;

int main(int argc, char * argv[]) {

  string raw_pt;
  cin >> raw_pt;
  vector<int> encryt_matrix(4, 0);
  vector<int> pt;
  vector<int> ct;

  for (int i = 1; i <= 4; ++i) {
    stringstream ss(argv[i]);
    ss >> encryt_matrix[i - 1];
  }
  
  for (int i = 0; i < raw_pt.size();i++) {
    pt.push_back((raw_pt[i]<'Z')?(raw_pt[i] - 'A' + 1):(raw_pt[i] - 'a' + 1));
  }
  
  int i = 0;
  while (i < raw_pt.size()) {
    ct.push_back((encryt_matrix[0]*pt[i] + encryt_matrix[1]*pt[i+1] - 1)%26 + 1);
    ct.push_back((encryt_matrix[2]*pt[i] + encryt_matrix[3]*pt[i+1] - 1)%26 + 1);
    i += 2;
  }
  
  for(auto c : ct)
    cout << c << " ";
  cout << endl;
    
  return 0;
}
