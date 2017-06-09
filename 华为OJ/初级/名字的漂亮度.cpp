#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(const int a, const int b) {
  return a > b;
}

int main() {
  int n;
  string name;

  cin >> n;

  while (n--) {
    cin >> name;

    int beauty = 0;
    int N = 26;
    int names[26] = {};
    int len = name.length();

    for (int i = 0; i < len; i++) {
      if (name[i] >= 'A' && name[i] <= 'Z') {
        names[name[i] - 'A']++;
      } else {
        names[name[i] - 'a']++;
      }
    }

    sort(names, names + N, cmp);

    for (int i = 0; i < N && names[i]; i++) {
      beauty += (N - i) * names[i];
    }

    cout << beauty << endl;
  }

  return 0;
}
