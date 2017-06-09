#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void findLongestDigitStr(string s) {
  int len = s.length();
  int maxLen = 0;
  int curLen = 0;
  string ds = "";

  for (int i = 0; i < len; i++) {
    if (isdigit(s[i])) {
      curLen++;

      if (curLen > maxLen) {
        maxLen = curLen;
        ds = s.substr(i - maxLen + 1, maxLen);
      } else if (curLen == maxLen) {
        ds += s.substr(i - curLen + 1, curLen);
      }
    } else {
      curLen = 0;
    }
  }

  if (maxLen) {
    cout << ds << ',' << maxLen << endl;
  } else {
    cout << 0 << endl;
  }
}

int main() {
  string s;

  getline(cin, s);

  findLongestDigitStr(s);

  return 0;
}
