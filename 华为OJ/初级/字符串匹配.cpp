#include <iostream>
#include <string>

using namespace std;

bool IsAllCharExist(string a, string b) {
  int aLen = a.length();
  int bLen = b.length();

  for (int i = 0; i < aLen; i++) {
    if (b.find(a[i]) == string::npos) {
      return false;
    }
  }

  return true;
}

int main() {
  string ss, ls;

  getline(cin, ss);
  getline(cin, ls);

  if (IsAllCharExist(ss, ls)) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }

  return 0;
}
