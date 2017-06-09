#include <iostream>
#include <string>

using namespace std;

int CalcCapital(string str) {
  int capital = 0;
  int len = str.length();

  for (int i = 0; i < len; i++) {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      capital++;
    }
  }

  return capital;
}

int main() {
  string s;

  getline(cin, s);

  int count = CalcCapital(s);

  cout << count << endl;

  return 0;
}
