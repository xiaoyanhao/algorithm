#include <iostream>

using namespace std;

int main() {
  unsigned int n;
  int count = 0;

  cin >> n;

  while (n) {
    n &= n - 1;
    count++;
  }

  cout << count << endl;

  return 0;
}
