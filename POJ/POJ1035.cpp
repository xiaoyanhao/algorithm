# include <iostream>
# include <string>
using namespace std;
string s[10005], str;

bool solve(int n) {
    int i, j, k;
    int len1 = s[n].size(), len2 = str.size();
    switch(len1 - len2) {
        case 1:
            k = 0;
            for (i = j = 0; j < len1; ) {
                if (str[i] != s[n][j]) {
                    k++;
                    j++;
                } else {
                    i++;
                    j++;
                }
            }
            return (k == 1) ? true : false;
            break;
        case 0:
            k = 0;
            for (i = j = 0; i < len2; i++, j++) {
                if (str[i] != s[n][j]) {
                    k++;
                }
            }
            return (k == 1) ? true : false;
            break;
        case -1:
            k = 0;
            for (i = j = 0; i < len2; ) {
                if (str[i] != s[n][j]) {
                    k++;
                    i++;
                } else {
                    i++;
                    j++;
                }
            }
            return (k == 1) ? true : false;
            break;
        default:
            return false;
            break;
    }
}

int main() {
    int i = 0, j, k;
    while (cin >> s[i] && s[i] != "#") {
        i++;
    }
    while (cin >> str && str != "#") {
        for (j = 0; j < i; j++) {
            if (str == s[j]) {
                cout << str << " is correct" << endl;
                break;
            }
        }
        if (j == i) {
            cout << str << ":";
            for (k = 0; k < i; k++) {
                if (solve(k)) {
                    cout << " " << s[k];
                }
            }
            cout << endl;
        }
    }
    return 0;
}

