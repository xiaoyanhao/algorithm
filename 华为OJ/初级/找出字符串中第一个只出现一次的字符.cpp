#include <iostream>
#include <string>

using namespace std;

char FindChar(string &s) {
  int ascii[256] = {};
  int len = s.length();
  char c = '.';

  for (int i = 0; i < len; i++) {
    ascii[s[i]]++;
  }

  for (int i = 0; i < len; i++) {
    if (ascii[s[i]] == 1) {
      c = s[i];
      break;
    }
  }

  return c;
}

int main() {
  string s;

  getline(cin, s);

  cout << FindChar(s) << endl;

  return 0;
}
