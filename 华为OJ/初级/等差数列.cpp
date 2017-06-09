#include <iostream>

using namespace std;

int main() {
  int n;

  cin >> n;

  if (n > 0) {
    cout << (3 * n + 1) * n / 2 << endl;
    return 0;
  } else {
    return -1;
  }
}
