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

  // This program must accept four arguments of the encrypt matrix
  if (argc != 5)
    return 1;

  string raw_pt;
  cin >> raw_pt;
  vector<int> encrypt_matrix(4, 0);
  vector<int> pt;
  vector<int> ct;

  // We use stringstream to convert string like "12" to int 12
  for (int i = 1; i <= 4; ++i) {
    stringstream ss(argv[i]);
    ss >> encrypt_matrix[i - 1];
  }

  //Convert the chars in plain text into their corresponding numbers
  for (int i = 0; i < raw_pt.size();i++) {
    pt.push_back((raw_pt[i]<='Z')?(raw_pt[i] - 'A'):(raw_pt[i] - 'a'));
  }
  
  //Add a 0 to plain text if the lenth of it is odd 
  if ((raw_pt.size()%2) == 1)
    pt.push_back(0);

  //Calculate the ciphered text using encrypt_matrix
  int i = 0;
  while (i < raw_pt.size()) {
    ct.push_back((encrypt_matrix[0]*pt[i] + encrypt_matrix[1]*pt[i+1])%26);
    ct.push_back((encrypt_matrix[2]*pt[i] + encrypt_matrix[3]*pt[i+1])%26);
    i += 2;
  }

  //Print out the plain text
  for (auto c : ct)
    cout << (char)(c + 'a');
  cout << endl;
  
  return 0;
}
