#include <iostream>

using namespace std;

int main() {
  int n;

  cin >> n;

  int *s = new int[n];
  int *l = new int[n];
  int *r = new int[n];

  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }

  for (int i = 0; i < n; i++) {
    l[i] = 1;
    for (int j = 0; j < i; j++) {
      if (s[i] > s[j] && l[i] <= l[j]) {
        l[i] = l[j] + 1;
      }
    }
  }

  for (int i = n - 1; i >= 0; i--) {
    r[i] = 1;
    for (int j = n - 1; j > i; j--) {
      if (s[i] > s[j] && r[i] <= r[j]) {
        r[i] = r[j] + 1;
      }
    }
  }

  int k = 0;

  for (int i = 0; i < n; i++) {
    if (l[i] + r[i] > k) {
      k = l[i] + r[i] - 1;
    }
  }

  cout << n - k << endl;

  delete[] s;
  delete[] l;
  delete[] r;

  return 0;
}
