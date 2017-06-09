#include <iostream>

using namespace std;

int main() {
    int n, m, need[501], value[501], best[100001] = {};

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> need[i] >> value[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= need[i]; j--) {
            if (best[j] < best[j - need[i]] + value[i]) {
                best[j] = best[j - need[i]] + value[i];
            }
        }
    }

    cout << best[m] << endl;

    return 0;
}

