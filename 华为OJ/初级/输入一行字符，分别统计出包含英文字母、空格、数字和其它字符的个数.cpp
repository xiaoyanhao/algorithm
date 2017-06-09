#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;

  getline(cin, s);

  int len = s.length();
  int english = 0, blank = 0, number = 0, other = 0;

  for (int i = 0; i < len; i++) {
    char c = s[i];
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
      english++;
    } else if (c >= '0' && c <= '9') {
      number++;
    } else if (c == ' ') {
      blank++;
    } else {
      other++;
    }
  }

  cout << english << endl << blank << endl << number << endl << other << endl;

  return 0;
}
