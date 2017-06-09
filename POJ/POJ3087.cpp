# include <iostream>
# include <string>
using namespace std;

int main() {
    int n, c, i, j, k;
    cin >> n;
    for (k = 1; k <= n; k++) {
        string s1, s2, S1, S2, s;
        int count = 0;
        bool flag = false;
        cin >> c >> s1 >> s2 >> s;
        S1 = s1;
        S2 = s2;
        while (1) {
            string temp = "";
            for (i = 0; i < c; i++) {
                temp = temp + s2[i] + s1[i];
            }
            count++;
            s1 = temp.substr(0, c);
            s2 = temp.substr(c, c);
            if (temp == s) {
                break;
            }
            if (S1 == s1 && S2 == s2) {
                flag = true;
                break;
            }
        }
        if (flag) {
            cout << k << " " << -1 << endl;
        } else {
            cout << k << " " << count << endl;
        }
    }
    return 0;
}

