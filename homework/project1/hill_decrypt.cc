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

int modulo(int dividend, int divisor){
  /* The normal operator % may return a negative result which we don't want,
     so we rewrite the % to get the result which is always positive(or zero).
  */
  if (dividend >= 0)
    return (dividend % divisor);
  else
    return (dividend % divisor + divisor);
}

int quotient(int dividend, int divisor){
  /* The quotient is not defined in the modulo case,
     so we write the quotient in the modulo case*/
  for(int i=0;i<=26;i++){
    if ((i*divisor)%26 == dividend)
      return i;
  }
}

int main(int argc, char * argv[]) {

  string raw_ct;
  cout << "Enter the ciphered text: ";
  cin >> raw_ct;
  vector<int> encrypt_matrix(4, 0);
  vector<int> decrypt_matrix(4, 0);
  vector<int> ct;
  vector<int> pt;

  // We use stringstream to convert string like "12" to int 12
  for (int i = 1; i <= 4; ++i) { 
    stringstream ss(argv[i]);
    ss >> encrypt_matrix[i - 1];
  }

  //Calculate the decrypt_matrix
  int det = encrypt_matrix[0]*encrypt_matrix[3] - encrypt_matrix[1]*encrypt_matrix[2];
  decrypt_matrix[0] = encrypt_matrix[3];
  decrypt_matrix[1] = -encrypt_matrix[1];
  decrypt_matrix[2] = -encrypt_matrix[2];
  decrypt_matrix[3] = encrypt_matrix[0];
  for (int i = 0; i<4;i++){
    decrypt_matrix[i] = modulo(quotient(modulo(decrypt_matrix[i],26),det),26);    
  }
   
  //Convert the chars in ciphered text into their corresponding numbers 
  for (int i = 0; i < raw_ct.size();i++) {
    ct.push_back((raw_ct[i]<'Z')?(raw_ct[i] - 'A' + 1):(raw_ct[i] - 'a' + 1));
  }

  //Add a 0 to ciphered text if the lenth of it is odd 
  if ((raw_ct.size()%2) == 1)
    ct.push_back(0);

  //Calculate the plain text using decrypt_matrix
  int i = 0;
  while (i < raw_ct.size()) {
    pt.push_back((decrypt_matrix[0]*ct[i] + decrypt_matrix[1]*ct[i+1] - 1)%26 + 1);
    pt.push_back((decrypt_matrix[2]*ct[i] + decrypt_matrix[3]*ct[i+1] - 1)%26 + 1);
    i += 2;
  }

  //Print out the plain text
  cout << "The plain text is: ";
  for (auto c : pt)
    cout << (char)(c + 'a' -1);
  cout << endl;
    
  return 0;
}
