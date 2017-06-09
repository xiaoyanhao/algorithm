#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>

using namespace std;

vector<string> split(const string &s, char delim) {
  vector<string> substr;
  istringstream iss(s);
  string item;

  while (!iss.eof()) {
    getline(iss, item, delim);
    substr.push_back(item);
  }

  return substr;
}

bool isNumber(string s) {
  if (s == "") {
    return false;
  }
  
  int len = s.length();

  for (int i = 0; i < len; i++) {
    if (!isdigit(s[i])) {
      return false;
    }
  }

  return true;
}

bool isValidIP(const string &s) {
  vector<string>::iterator it;
  vector<string> ip = split(s, '.');
  int size = ip.size();

  if (size != 4) {
    return false;
  }

  for (it = ip.begin(); it != ip.end(); it++) {
    if (isNumber(*it)) {
      int n = atoi((*it).c_str());
      if (n < 0 || n > 255) {
        return false;
      }
    } else {
      return false;
    }
  }

  return true;
}

int main() {
  string s;

  getline(cin, s);

  if (isValidIP(s)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}
