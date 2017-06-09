#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string getSequeOddNum(int m) {
  int first = m * m - (m - 1);
  int last = m * m + (m - 1);
  ostringstream convert;

  for (int i = first; i <= last; i += 2) {
    int num = i;
    convert << num << '+';
  }
  
  string s = convert.str();

  return s.substr(0, s.length() - 1);
}

int main() {
  int n;

  cin >> n;

  cout << getSequeOddNum(n) << endl;

  return 0;
}
