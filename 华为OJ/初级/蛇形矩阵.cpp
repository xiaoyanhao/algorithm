#include <iostream>

using namespace std;

int main() {
  int n;

  cin >> n;

  for (int x = 1; x <= n; x++) {
    int val = x * (x - 1) / 2 + 1;
    int step = x + 1;

    cout << val;

    for (int y = 2; y <= n - x + 1; y++) {
      cout << ' ' << val + step;
      val += step;
      step++;
    }

    cout << endl;
  }

  return 0;
}
