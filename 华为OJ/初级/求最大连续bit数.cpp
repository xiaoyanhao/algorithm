#include <iostream>

using namespace std;

int countConsecutiveBit(int n) {
  int count = 0;
  int maxCount = 0;
  int singleBit = 1;

  while (singleBit) {
    if (n & singleBit) {
      count++;

      if (count > maxCount) {
        maxCount = count;
      }
    } else {
      count = 0;
    }

    singleBit <<= 1;
  }

  return maxCount;
}

int main() {
  int n;

  cin >> n;

  cout << countConsecutiveBit(n) << endl;

  return 0;
}
