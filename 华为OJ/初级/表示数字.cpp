#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
  string s;

  getline(cin, s);

  string n = "";
  int len = s.length();
  bool flag = false;

  for (int i = 0; i < len; i++) {
    char c = s[i];

    if (isdigit(c) && !flag) {
      n += '*';
      flag = true;
    }

    if (!isdigit(c) && flag) {
      n += '*';
      flag = false;
    }

    n += c;
  }

  if (flag) {
    n += '*';
  }

  cout << n << endl;

  return 0;
}
