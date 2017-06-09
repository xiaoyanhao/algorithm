#include <iostream>
#include <cmath>

using namespace std;

int main() {
  float n;

  cin >> n;

  int ans = round(n);

  if (!ans) {
    cout << 0 << endl;
  } else {
    cout << ans << endl;
  }

  return 0;
}
