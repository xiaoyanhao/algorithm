#include <iostream>
#include <string>

using namespace std;

bool isMatch(string reg, string str) {
  int regLen = reg.length();
  int strLen = str.length();
  int j = 0;

  for (int i = 0; i < regLen; i++) {
    char regChar = reg[i];
    char strChar = str[j];

    if (regChar == strChar || regChar == '?') {
      j++;
    } else if (regChar == '*') {
      if (i == regLen - 1) {
        return true;
      }

      j = str.find(reg[i + 1], j);

      if (j == string::npos) {
        return false;
      }
    } else {
      return false;
    }
  }

  return j == strLen ? true : false;
}

int main() {
  string reg, str;

  getline(cin, reg);
  getline(cin, str);

  if (isMatch(reg, str)) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }

  return 0;
}
