#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;

    cin >> t;

    while (t--) {
        int n, m, a[102];

        cin >> n >> m;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        a[0] = 0;
        a[n + 1] = 101;

        int ans = 0;

        if (m >= n || n == 0) {
            ans = 100;
        } else {
            // 只有将连续的几个未提交都补提交，才能得到最大连续时间
            for (int i = 0; i <= n; i++) {
                if (i + 1 + m <= n + 1) {
                    ans = max(ans, a[i + 1 + m] - a[i] - 1);
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}