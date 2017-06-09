#include <iostream>

using namespace std;

int get_score(string s) {
    int score = 0;
    bool finished = false;
    string next_s = s;

    while (!finished) {
        string next_s = "";
        int size = s.size();
        char last = '#';
        finished = true;

        for (int i = 0; i < size; i++) {
            if (s[i] == last || s[i] == s[i + 1]) {
                score++;
                finished = false;
            } else {
                next_s += s[i];
            }
            last = s[i];
        }

        s = next_s;
    }

    return score;
}

int main() {
    int t;

    cin >> t;

    while (t--) {
        string s;

        cin >> s;

        int size = s.size(), score = 0;

        for (int i = 0; i < size; i++) {
            for (char c = 'A'; c <= 'C'; c++) {
                string ss = s;
                string sss = ss.insert(i, string(1, c));
                score = max(score, get_score(sss));
            }
        }

        cout << score << endl;
    }

    return 0;
}