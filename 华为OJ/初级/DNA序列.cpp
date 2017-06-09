#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
  string s;
  int minLen;

  cin >> s >> minLen;

  int len = s.length();
  int maxCount = 0;
  int index = 0;

  for (int i = 0; i <= len - minLen; i++) {
    int count = 0;

    for (int j = 0; j < minLen; j++) {
      if (s[i + j] == 'G' || s[i + j] == 'C') {
        count++;
      }
    }

    if (count > maxCount) {
      maxCount = count;
      index = i;
    }
  }

  string ss = s.substr(index, minLen);

  cout << ss << endl;

  return 0;
}
