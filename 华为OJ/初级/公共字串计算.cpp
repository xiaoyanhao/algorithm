#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int getCommonStrLength(string a, string b) {
  int row = a.length() + 1;
  int col = b.length() + 1;
  int **p = new int*[row];
  int result = 0;

  for (int i = 0; i < row; i++) {
    p[i] = new int[col];
    for (int j = 0; j < col; j++) {
      p[i][j] = 0;
    }
  }

  for (int i = 1; i < row; i++) {
    for (int j = 1; j < col; j++) {
      char ac = a[i - 1];
      char bc = b[j - 1];
      if (ac == bc || abs(ac - bc) == 32) {
        p[i][j] = p[i - 1][j - 1] + 1;
      } else {
        p[i][j] = 0;
      }

      if (p[i][j] > result) {
        result = p[i][j];
      }
    }
  }

  for (int i = 0; i < row; i++) {
    delete[] p[i];
  }

  delete[] p;

  return result;
}

int main() {
  string a, b;

  cin >> a >> b;

  cout << getCommonStrLength(a, b) << endl;

  return 0;
}
