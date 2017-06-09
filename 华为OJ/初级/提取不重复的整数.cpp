#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
  string s;

  cin >> s;

  reverse(s.begin(), s.end());

  int len = s.length();
  string ss = "";

  for (int i = 0; i < len; i++) {
    char c = s[i];

    if (s.find(c) == i) {
      ss += c;
    }
  }

  if (ss.length() > 1 && ss[0] == '0') {
    ss.erase(0, 1);
  }

  cout << ss << endl;

  return 0;
}
