# include <cstdio>
# include <iostream>
# include <vector>
# include <cstdlib>
using namespace std;

const int maxn = 100005;
const int mod = 90001;
int snow[maxn][6];
vector<int> hash[mod];

bool Same(int a, int b) {
    for (int i = 0; i < 6; i++) {
        if ((snow[a][0] == snow[b][(i + 0) % 6] &&
            snow[a][1] == snow[b][(i + 1) % 6] &&
            snow[a][2] == snow[b][(i + 2) % 6] &&
            snow[a][3] == snow[b][(i + 3) % 6] &&
            snow[a][4] == snow[b][(i + 4) % 6] &&
            snow[a][5] == snow[b][(i + 5) % 6])
            ||
            (snow[a][5] == snow[b][(i + 0) % 6] &&
            snow[a][4] == snow[b][(i + 1) % 6] &&
            snow[a][3] == snow[b][(i + 2) % 6] &&
            snow[a][2] == snow[b][(i + 3) % 6] &&
            snow[a][1] == snow[b][(i + 4) % 6] &&
            snow[a][0] == snow[b][(i + 5) % 6])
        ) {
            return true;
        }
    }
    return false;
}

int main() {
    int n, i, j, k, sum, key;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < 6; j++) {
            scanf("%d", &snow[i][j]);
        }
    }
    for (i = 0; i < n; i++) {
        sum = 0;
        for (j = 0; j < 6; j++) {
            sum += snow[i][j];
        }
        key = sum % mod;
        vector<int>::iterator it;
        for (it = hash[key].begin(); it != hash[key].end(); it++) {
            if (Same(*it, i)) {
                printf("Twin snowflakes found.\n");
                return 0;
            }
        }
        hash[key].push_back(i);
    }
    printf("No two snowflakes are alike.\n");
    return 0;
} 
