#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int LongestCommonSubsequence(string a, string b) {
    int row = a.length() + 1;
    int col = b.length() + 1;
    int p[row][col];

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            p[i][j] = 0;
        }
    }

    for (int i = 1; i < row; i++) {
        for (int j = 1; j < col; j++) {
            if (a[i - 1] == b[j - 1]) { // 注意这里要减1
                p[i][j] = p[i - 1][j - 1] + 1;
            } else {
                p[i][j] = max(p[i - 1][j], p[i][j - 1]);
            }
        }
    }

    return p[row - 1][col - 1];
}

int main(int argc, char const *argv[]) {
    string a, b;

    while (cin >> a >> b) {
        cout << LongestCommonSubsequence(a, b) << endl;
    }

    return 0;
}