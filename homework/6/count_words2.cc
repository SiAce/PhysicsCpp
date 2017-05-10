#include <string>
#include <iostream>
#include <fstream>
#include <cctype>

using std::string;
using std::ifstream;
using std::istream;
using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::getline;
using std::isspace;

int main (int argc, char * argv[])
{
    if (argc != 1 && argc != 2) {
        cerr << "Usage: " << argv[0] << endl;
	cerr << argv[0] << "input_file" << endl;
        return 1;
    }
    string line;
    unsigned int count{0};
    unsigned int line_count{0};
    unsigned int line_index{1};

    if (argc == 1) {
      while (getline(cin, line)) {
	line_count = 0;
        bool space_before{true};
        for (auto c: line) {
            if (isspace(c)) {
                space_before = true;
            } else if (space_before) {
                line_count++;
                space_before = false;
            }
        }
	cout << "There are " << line_count
	     <<" words in line " << line_index << endl; 
	count += line_count;
	++line_index;
      }
    cout << "There are totally " << count << " words" << endl;
    }

    if (argc == 2) {
      ifstream input{argv[1]};
      while (getline(input, line)) {
	line_count = 0;
        bool space_before{true};
        for (auto c: line) {
            if (isspace(c)) {
                space_before = true;
            } else if (space_before) {
                line_count++;
                space_before = false;
            }
        }
	cout << "There are " << line_count
	     <<" words in line " << line_index << endl; 
	count += line_count;
	++line_index;
      }
    cout << "There are totally " << count << " words" << endl;
    }    
}
