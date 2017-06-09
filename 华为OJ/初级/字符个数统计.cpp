#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;

  getline(cin, s);

  int ascii[128] = {};
  int len = s.length();

  for (int i = 0; i < len; i++) {
    if (s[i] >= 0 && s[i] <= 127) {
      ascii[s[i]]++;
    }
  }

  int count = 0;

  for (int i = 0; i < 128; i++) {
    if (ascii[i]) {
      count++;
    }
  }

  cout << count << endl;

  return 0;
}
