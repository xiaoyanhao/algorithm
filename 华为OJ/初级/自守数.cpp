#include <iostream>

using namespace std;

bool isAutomorphicNumber(int n) {
  int square = n * n;

  while (n) {
    int a = square % 10;
    int b = n % 10;

    if (a == b) {
      square /= 10;
      n /= 10;
    } else {
      return false;
    }
  }

  return true;
}

int calcAutomorphicNumbers(int n) {
  int count = 0;

  for (int i = 0; i <= n; i++) {
    if (isAutomorphicNumber(i)) {
      count++;
    }
  }

  return count;
}

int main() {
  int n;

  cin >> n;

  cout << calcAutomorphicNumbers(n) << endl;

  return 0;
}
