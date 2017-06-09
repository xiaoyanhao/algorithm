#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  string s;

  getline(cin, s);

  reverse(s.begin(), s.end());

  int len = s.length();

  for (int i = 0, j = 0; i < len; i = j + 1) {
    while (i < len && s[i] == ' ') {
      i++;
    }

    j = i + 1;

    while (j < len && s[j] != ' ') {
      j++;
    }

    reverse(s.begin() + i, s.begin() + j);
  }

  cout << s << endl;

  return 0;
}
