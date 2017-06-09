#include <iostream>

using namespace std;

int main() {
  int n;

  cin >> n;

  for (int i = 0; i <= 20; i++) {
    for (int j = 0; j <= 33; j++) {
      int k = 100 - i - j;

      if (15 * i + 9 * j + k == 300) {
        cout << i << ' ' << j << ' ' << k << endl;
      }
    }
  }

  return 0;
}
