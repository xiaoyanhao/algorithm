#include <iostream>
#include <vector>

using namespace std;

int fama(int n, vector<int> weight, vector<int> nums) {
  int maxWeight = 0;
  int count = 1;

  for (int i = 0; i < n; i++) {
    maxWeight += weight[i] * nums[i];
  }

  vector<bool> flag(maxWeight + 1, false);
  flag[0] = true;

  for (int i = 0; i < n; i++) {
    for (int k = maxWeight; k > 0; k--) {
      for (int j = 1; j <= nums[i]; j++) {
        int t = k - weight[i] * j;

        if (t >= 0 && flag[t] && !flag[k]) {
          flag[k] = true;
          count++;
        }
      }
    }
  }

  return count;
}

int main() {
  int n;

  cin >> n;

  vector<int> weight(n);
  vector<int> nums(n);

  for (int i = 0; i < n; i++) {
    cin >> weight[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  cout << fama(n, weight, nums) << endl;

  return 0;
}
