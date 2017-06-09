# include <iostream>
# include <string>
using namespace std;

int main() {
    string s, t;
    while (cin >> s >> t) {
        int i = 0, j = 0;
        while (true) {
            if (i == s.size()) {
                cout << "Yes" << endl;
                break;
            } else if (i < s.size() && j == t.size()) {
                cout << "No" << endl;
                break;
            }
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }
    }
    return 0;
}
