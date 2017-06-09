#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int n) {
  if (n < 2) {
    return false;
  }

  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return false;
    }
  }

  return true;
}

void getMaxArray(int m, int n) {
  vector<int> primes;

  for (int i = m; i <= n; i++) {
    if (isPrime(i)) {
      primes.push_back(i);
    }
  }

  int size = primes.size();
  int maxCount = 0;
  int maxDiff = 0;
  int first = 0;

  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      int diff = primes[j] - primes[i];
      int count = 2;

      for (int k = j + 1; k < size; k++) {
        if (primes[k] - primes[i] == diff * count) {
          count++;
        }
      }

      if ((count > maxCount) || (count == maxCount && diff >= maxDiff)) {
        maxCount = count;
        maxDiff = diff;
        first = primes[i];
      }
    }
  }

  for (int i = 0; i < maxCount; i++) {
    cout << first + i * maxDiff << endl;
  }
}

int main() {
  int m, n;

  cin >> m >> n;

  getMaxArray(m, n);

  return 0;
}
