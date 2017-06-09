#include <iostream>

using namespace std;

int GCD(int a, int b) {
  return b > 0 ? GCD(b, a % b) : a;
}

int LCM(int a, int b) {
  return a / GCD(a, b) * b;
}

int main() {
  int a, b;

  cin >> a >> b;

  int lcm = LCM(a, b);

  cout << lcm << endl;

  return 0;
}
