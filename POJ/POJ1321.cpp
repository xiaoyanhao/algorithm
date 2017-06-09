# include <iostream>
# include <cstring>
using namespace std;

int n, k, ans, vis_col[10];
char map[10][10];

void DFS(int x, int count) {
    if (count == k) {
       ans++;
       return;
    }
    if (x >= n) {
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!vis_col[i] && map[x][i] == '#') {
            vis_col[i] = 1;
            DFS(x + 1, count + 1);
            vis_col[i] = 0;
        }
    }
    DFS(x + 1, count);
}

int main() {
    while (cin >> n >> k && n != -1 && k != -1) {
        memset(vis_col, 0, sizeof(vis_col));
        ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> map[i];
        }
        DFS(0, 0);
        cout << ans << endl;
    }
    return 0;
}

