# include <iostream>
# include <cstring>
using namespace std;
int p, q, flag, vis[30][30], row[30], col[30];
int dir[8][2] = {{-1, -2}, {1, -2}, {-2, -1}, {2, -1}, {-2, 1}, {2, 1}, {-1, 2}, {1, 2}};

void dfs(int x, int y, int num) {
    row[num] = x;
    col[num] = y;
    if (num == p * q) {
        flag = 1;
        return;
    }
    for (int i = 0; i < 8; i++) {
        int tmp_x = x + dir[i][0];
        int tmp_y = y + dir[i][1];
        if (tmp_x >= 1 && tmp_x <= p && tmp_y >= 1 && tmp_y <= q && !vis[tmp_x][tmp_y] && !flag) {
            vis[tmp_x][tmp_y] = 1;
            dfs(tmp_x, tmp_y, num + 1);
            vis[tmp_x][tmp_y] = 0;
        }
    }
}

int main() {
    int Case, i, k;
    cin >> Case;
    for (k = 1; k <= Case; k++) {
        cin >> p >> q;
        memset(vis, 0, sizeof(vis));
        vis[1][1] = 1;
        flag = 0;
        dfs(1, 1, 1);
        cout << "Scenario #" << k << ":" << endl;
        if (flag) {
            for (i = 1; i <= p * q; i++) {
                char c = col[i] + 'A' - 1;
                cout << c << row[i];
            }
        } else {
            cout << "impossible";
        }
        if (k == Case) {
            cout << endl;
        } else {
            cout << endl << endl;
        }
    }
    return 0;
}

