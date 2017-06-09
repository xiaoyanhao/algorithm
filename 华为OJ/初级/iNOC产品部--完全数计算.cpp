#include <iostream>

using namespace std;

int count(int n) {
  int result = 0;

  for (int i = 2; i <= n; i++) {
    int sum = 1;

    for (int j = 2; j * 2 <= i; j++) {
      if (i % j == 0) {
        sum += j;
      }
    }

    if (sum == i) {
      result++;
    }
  }

  return result;
}

int main() {
  int n;

  cin >> n;

  cout << count(n) << endl;

  return 0;
}
