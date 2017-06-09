#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;

  getline(cin, s);

  int pos = s.find_last_of(' ');

  if (pos != string::npos) {
    s = s.substr(pos + 1);
  }

  cout << s.length() << endl;
  
  return 0;
}
