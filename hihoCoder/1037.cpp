#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, best[201][201] = {}, rewards[201][201], ans = 0;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> rewards[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            best[i][j] = max(best[i - 1][j - 1], best[i - 1][j]) + rewards[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        ans = max(ans, best[n][i]);
    }

    cout << ans << endl;

    return 0;
}

