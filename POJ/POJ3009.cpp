# include <iostream>
# include <cstring>
using namespace std;
const int INF = (1 << 29);
int col, row, sx, sy, map[25][25], min_step;
int dir[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

void DFS(int x, int y, int step) {
    if (step >= 10) {
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if (nx >= 0 && nx < row && ny >= 0 && ny < col && map[nx][ny] != 1) {
            while (!(map[nx][ny] == 1 || map[nx][ny] == 3)) {
                nx += dir[i][0];
                ny += dir[i][1];
                if (nx < 0 || nx >= row || ny < 0 || ny >= col) {
                    break;
                }
            }
            if (nx < 0 || nx >= row || ny < 0 || ny >= col) {
                continue;
            }
            if (map[nx][ny] == 3) {
                min_step = min(min_step, step + 1); 
            } else if (map[nx][ny] == 1) {
                map[nx][ny] = 0;
                DFS(nx - dir[i][0], ny - dir[i][1], step + 1);
                map[nx][ny] = 1;
            }
        }
    }
}

int main() {
    int i, j;
    while (cin >> col >> row && row && col) {
        min_step = INF;
        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                cin >> map[i][j];
                if (map[i][j] == 2) {
                    sx = i;
                    sy = j;
                }
            }
        }
        DFS(sx, sy, 0);
        if (min_step != INF) {
            cout << min_step << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}
