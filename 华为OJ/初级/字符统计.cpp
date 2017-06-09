#include <iostream>
#include <string>
#include <cctype>
#include <map>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;

typedef struct Cmp {
  bool operator() (const pair<char, int> &a, const pair<char, int> &b) const {
    return a.second == b.second ? a.first < b.first : a.second > b.second;
  }  
} Cmp;

void countChar(string str) {
  map<char, int> m;
  int len = str.length();

  for (int i = 0; i < len; i++) {
    char c = str[i];

    if (isdigit(c) || isalpha(c) || isspace(c)) {
      if (m.count(c) > 0) {
        m[c]++;
      } else {
        m[c] = 0;
      }
    }
  }

  set<pair<char, int>, Cmp> st(m.begin(), m.end(), Cmp());
  set<pair<char, int>, Cmp>::iterator it;
  string result = "";

  for (it = st.begin(); it != st.end(); it++) {
    result += it->first;
  }

  cout << result << endl;
}

int main() {
  string s;

  getline(cin, s);

  countChar(s);

  return 0;
}
