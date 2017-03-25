/* 
Author: SiAce
Created on March 17 12:47:50 2017
*/
#include <iostream>

using namespace std;

int main() {
	int n = 0, m = 0;
	int chicken = 0, rabbits = 0;
	cout << "ÇëÊäÈë n,m:";
	cin >> n >> m;
	rabbits = (m - 2 * n) / 2;//calculate the number of rabbits
	chicken = (4 * n - m) / 2;//calculate the number of chicken
	if (((m - 2 * n) % 2 == 0) && (rabbits >= 0) && (chicken >= 0) && (m >= 0) && (n >= 0)) {
		//only if (m - 2 * n) / 2 is a integer and rabbits,chicken,m,n is no less than 0, we have the solution
		cout << "¼¦:" << chicken << ",ÍÃ:" << rabbits;
	}
	else
		cout << "ÎÞ½â";
	return 0;
}