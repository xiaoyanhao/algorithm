# include <iostream>
# include <cstring>
# include <string>
using namespace std;

int map[45][45], ip, V1, V2, M, link[405];
bool city[405][405], vis[405];
int direction[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool dfs(int x) {
    for (int y = 1; y <= V2; y++) {
        if (city[x][y] && !vis[y]) {
            vis[y] = true;
            if (link[y] == 0 || dfs(link[y])) {
                link[y] = x;
                return true;
            }
        }
    }
    return false;
}

void Hungary() {
    for (int x = 1; x <= V1; x++) {
        memset(vis, false, sizeof(vis));
        if (dfs(x)) {
            M++;
        }
    }
}
int main() {
    int N, row, col, i, j, k;
    cin >> N;
    while (N--) {
        memset(map, 0, sizeof(map));
        memset(city, false, sizeof(city));
        memset(link, 0, sizeof(link));
        ip = M = 0;
        cin >> row >> col;
        string s;
        for (i = 1; i <= row; i++) {
            cin >> s;
            for (j = 1; j <= col; j++) {
                if (s[j - 1] == '*') {
                    map[i][j] = ++ip;
                }
            }
        }
        for (i = 1; i <= row; i++) {
            for (j = 1; j <= col; j++) {
                if (map[i][j]) {
                    for (k = 0; k < 4; k++) {
                        int x = i + direction[k][0];
                        int y = j + direction[k][1];
                        if (map[x][y]) {
                            city[map[i][j]][map[x][y]] = true;
                        }
                    }
                }
            }
        }
        V1 = V2 = ip;
        Hungary();
        cout << ip - M / 2 << endl;
    }
    return 0;
}

