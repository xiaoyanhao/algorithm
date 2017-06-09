#include <iostream>
#include <string>

using namespace std;

void toLowerCase(string &s) {
  int len = s.length();

  for (int i = 0; i < len; i++) {
    char c = s[i];
    s[i] = c >= 'A' && c <= 'Z' ? c + 32 : c;
  }
}

int main() {
  string s;
  string c;

  getline(cin, s);
  getline(cin, c);

  toLowerCase(s);
  toLowerCase(c);

  int len = s.length();
  int count = 0;

  for (int i = 0; i < len; i++) {
    if (s[i] == c[0]) {
      count++;
    }
  }

  cout << count << endl;

  return 0;
}
