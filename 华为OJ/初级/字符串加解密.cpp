#include <iostream>
#include <string>

using namespace std;

void encrypt(string s) {
  int len = s.length();

  for (int i = 0; i < len; i++) {
    char c = s[i];

    if (c >= '0' && c <= '9') {
      s[i] = '0' + (c - '0' + 1) % 10;
    } else if (c >= 'a' && c <= 'z') {
      s[i] = 'A' + (c - 32 - 'A' + 1) % 26;
    } else if (c >= 'A' && c <= 'Z') {
      s[i] = 'a' + (c + 32 - 'a' + 1) % 26;
    }
  }

  cout << s << endl;
}

void unencrypt(string s) {
  int len = s.length();

  for (int i = 0; i < len; i++) {
    char c = s[i];

    if (c >= '0' && c <= '9') {
      s[i] = '0' + (c - '0' - 1 + 10) % 10;
    } else if (c >= 'a' && c <= 'z') {
      s[i] = 'A' + (c - 32 - 'A' - 1 + 26) % 26;
    } else if (c >= 'A' && c <= 'Z') {
      s[i] = 'a' + (c + 32 - 'a' - 1 + 26) % 26;
    }
  }

  cout << s << endl;
}

int main() {
  string sa, sb;

  getline(cin, sa);
  getline(cin, sb);

  encrypt(sa);
  unencrypt(sb);

  return 0;
}
