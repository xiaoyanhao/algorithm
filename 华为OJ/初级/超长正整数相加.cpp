#include <iostream>
#include <string>

using namespace std;

string AddLongInteger(string sa, string sb) {
  int alen = sa.length();
  int blen = sb.length();
  int len = alen > blen ? alen : blen;
  int *a = new int[len + 1];
  int *b = new int[len + 1];
  string result = "";

  for (int i = 0; i < alen; i++) {
    a[i] = sa[alen - 1 - i] - '0';
  }

  for (int i = 0; i < blen; i++) {
    b[i] = sb[blen - 1 - i] - '0';
  }

  for (int i = 0; i < len; i++) {
    a[i] += b[i];
    a[i + 1] += a[i] / 10;
    a[i] %= 10;
  }

  if (a[len]) {
    result += a[len];
  }

  for (int i = len - 1; i >= 0; i--) {
    result += a[i];
  }

  delete[] a;
  delete[] b;

  return result;
}

int main() {
  string a, b;

  cin >> a >> b;

  cout << AddLongInteger(a, b) << endl;

  return 0;
}
