#include <iostream>

using namespace std;

int main() {
  int n;
  int count = 0;

  cin >> n;

  for (int i = 7; i <= n; i++) {
    if (i % 7 == 0) {
      count++;
    } else {
      int j = i;

      while (j) {
        if (j % 10 == 7) {
          count++;
          break;
        } else {
          j /= 10;
        }
      }
    }
  }

  cout << count << endl;

  return 0;
}
