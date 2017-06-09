#include <iostream>
#include <cmath>

#define LIMIT 1E-6

using namespace std;

bool is24points(double *num, int n) {
  if (n == 1) {
    if (fabs(num[0] - 24) < LIMIT) {
      return true;
    }
    return false;
  }

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      double a = num[i];
      double b = num[j];

      num[j] = num[n - 1];

      num[i] = a + b;
      if (is24points(num, n - 1)) {
        return true;
      }

      num[i] = a - b;
      if (is24points(num, n - 1)) {
        return true;
      }

      num[i] = b - a;
      if (is24points(num, n - 1)) {
        return true;
      }

      num[i] = a * b;
      if (is24points(num, n - 1)) {
        return true;
      }

      if (b - 0 > LIMIT) {
        num[i] = a / b;
        if (is24points(num, n - 1)) {
          return true;
        }
      }

      if (a - 0 > LIMIT) {
        num[i] = b / a;
        if (is24points(num, n - 1)) {
          return true;
        }
      }

      num[i] = a;
      num[j] = b;
    }
  }

  return false;
}

int main() {
  double num[4];

  cin >> num[0] >> num[1] >> num[2] >> num[3];

  if (is24points(num, 4)) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }

  return 0;
}
