#include <iostream>
#include <vector>

using namespace std;

void matrixMultiply(vector< vector<int> > a, vector< vector<int> > b, vector< vector<int> > &r, int x, int y, int z) {
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      int sum = 0;

      for (int k = 0; k < z; k++) {
        sum += a[i][k] * b[k][j];
      }

      r[i][j] = sum;
    }
  }
}

int main() {
  int x, y, z;

  cin >> x >> y >> z;

  vector< vector<int> > a(x, vector<int>(y));
  vector< vector<int> > b(y, vector<int>(z));
  vector< vector<int> > r(x, vector<int>(z));

  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      cin >> a[i][j];
    }
  }

  for (int i = 0; i < y; i++) {
    for (int j = 0; j < z; j++) {
      cin >> b[i][j];
    }
  }

  matrixMultiply(a, b, r, x, y, z);

  for (int i = 0; i < x; i++) {
    cout << r[i][0];
    for (int j = 1; j < z; j++) {
      cout << ' ' << r[i][j];
    }
    cout << endl;
  }

  return 0;
}
