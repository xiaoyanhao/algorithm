#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  int n, m;
  int negative = 0;
  int positive = 0;
  int positiveSum = 0;

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> m;

    if (m > 0) {
      positive++;
      positiveSum += m;
    } else if (m < 0) {
      negative++;
    }
  }

  cout << negative << ' ';

  if (positive) {
    if (positiveSum % positive == 0) {
      cout << positiveSum / positive;
    } else {
      cout << fixed << setprecision(1) << (float)positiveSum / positive;
    }
  } else {
    cout << 0;
  }

  return 0;
}
