#include <iostream>

using namespace std;

int main() {
  int n, pos;

  cin >> n;

  if (n <= 2) {
    pos = -1;
  } else if (n % 2 == 1) {
    pos = 2;
  } else if (n % 4 == 0) {
    pos = 3;
  } else if (n % 4 == 2) {
    pos = 4;
  }

  cout << pos << endl;

  return 0;
}
