# include <iostream>
# include <cstring>
using namespace std;

int main() {
    int n, i, j, len, len2, ans, next[10005] = {};
    string s, t;
    cin >> n;
    while (n--) {
        cin >> t >> s;
        next[0] = -1;
        len = t.size();
        for (i = 0, j = -1; i < len; ) {
            if (j == -1 || t[i] == t[j]) {
                next[++i] = ++j;
            } else {
                j = next[j];
            }
        }
        len2 = s.size();
        for (i = j = ans = 0; i < len2; ) {
            if (j == -1 || s[i] == t[j]) {
                ++i;
                ++j;
            } else {
                j = next[j];
            }
            if (j == len) {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
