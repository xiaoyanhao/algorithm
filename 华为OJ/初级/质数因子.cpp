#include <iostream>
#include <string>

using namespace std;

string getPrimeFactors(long n) {
  string primeFactors = "";

  for (long i = 2; i <= n; i++) {
    while (n % i == 0) {
      primeFactors += i + '0';
      primeFactors += ' ';
      n /= i;
    }
  }

  return primeFactors;
}

int main() {
  long n;

  cin >> n;

  cout << getPrimeFactors(n) << endl;

  return 0;
}
