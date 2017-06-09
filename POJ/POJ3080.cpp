# include <iostream>
# include <string>
using namespace std;

int main() {
    int n, m, i, j, k;
    cin >> n;
    while (n--) {
        string s[15];
        cin >> m;
        for (i = 0; i < m; i++) {
            cin >> s[i];
        }
        string ans = "";
        for (i = 3; i <= 60; i++) {
            for (j = 0; j < 60 - 3; j++) {
                string tmp = s[0].substr(j, i);
                bool flag = true;
                for (k = 1; k < m; k++) {
                    if (s[k].find(tmp) == static_cast<int>(string::npos)) {
                        flag = false;
                    }
                }
                if (flag && ans.size() < tmp.size()) {
                    ans = tmp;
                } else if (flag && ans.size() == tmp.size() && ans > tmp) {
                    ans = tmp;
                }
            }
        }
        if (ans == "") {
            cout << "no significant commonalities" << endl;
        } else {
            cout << ans << endl;
        }
    }
    return 0;
} 
