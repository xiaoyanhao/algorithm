#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool findCombination(vector<int> num, int sum) {
  int size = num.size();
  int len = 1 << size;
  for (int i = 1; i < len; i++) {
    int total = 0;

    for (int j = 0; j < size; j++) {
      if (i & (1 << j)) {
        total += num[j];
      }
    }

    if (total == sum) {
      return true;
    }
  }

  return false;
}

bool splitHalf(vector<int> num) {
  int total = 0;
  int threeSum = 0;
  int fiveSum = 0;
  int size = num.size();
  vector<int> others;

  for (int i = 0; i < size; i++) {
    int n = num[i];

    if (n % 5 == 0) {
      fiveSum += n;
    } else if (n % 3 == 0) {
      threeSum += n;
    } else {
      others.push_back(n);
    }

    total += n;
  }

  if (total % 2 == 0) {
    int diff = abs(fiveSum - threeSum);
    int othersSum = total - threeSum - fiveSum;
    return findCombination(others, (diff + othersSum) / 2);
  }

  return false;
}

int main() {
  int n, m;
  vector<int> num;

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> m;
    num.push_back(m);
  }

  if (splitHalf(num)) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }

  return 0;
}
