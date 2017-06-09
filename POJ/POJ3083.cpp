# include <iostream>
# include <queue>
# include <cstring>
using namespace std;
int col, row, sx, sy, ex, ey, vis[45][45];
int left_dir[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
int right_dir[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
char maze[45][45];

int DFS(int x, int y, int d, int dir[][2], int step = 1) {
    for (int i = 0; i < 4; i++) {
        int j = ((d + 3) % 4 + i) % 4;
        int nx = x + dir[j][0];
        int ny = y + dir[j][1];
        if (nx == ex && ny == ey) {
            return step + 1;
        }
        if (nx >= 0 && nx < row && ny >= 0 && ny < col && maze[nx][ny] != '#') {
            return DFS(nx, ny, j, dir, step + 1);
        }
    }
}

struct Node {
    int x, y, step;
    Node(int x1, int y1, int step1): x(x1), y(y1), step(step1) {}
};

int BFS() {
    Node node(sx, sy, 1);
    queue<Node> Q;
    memset(vis, 0, sizeof(vis));
    vis[sx][sy] = 1;
    Q.push(node);
    while (!Q.empty()) {
        node = Q.front();
        Q.pop();
        if (node.x == ex && node.y == ey) {
            return node.step;
        }
        vis[node.x][node.y] = 1;
        for (int i = 0; i < 4; i++) {
            int nx = node.x + left_dir[i][0];
            int ny = node.y + left_dir[i][1];
            if (nx >= 0 && nx < row && ny >= 0 && ny < col && !vis[nx][ny] &&
            maze[nx][ny] != '#') {
                vis[nx][ny] = 1;
                Node next(nx, ny, node.step + 1);
                Q.push(next);
            }
        } 
    }
    return 0;
}

int main() {
    int t, i, j, d1, d2;
    cin >> t;
    while (t--) {
        cin >> col >> row;
        for (i = 0; i < row; i++) {
            cin >> maze[i];
            for (j = 0; j < col; j++) {
                if (maze[i][j] == 'S') {
                    maze[i][j] = '.';
                    sx = i;
                    sy = j;
                } else if (maze[i][j] == 'E') {
                    maze[i][j] = '.';
                    ex = i;
                    ey = j;
                }
            }
        }
        if (sx == 0) {
            d1 = d2 = 3;
        } else if (sy == 0) {
            d1 = 2;
            d2 = 0;
        } else if (sx == row - 1) {
            d1 = d2 = 1;
        } else if (sy == col - 1) {
            d1 = 0;
            d2 = 2;
        }
        cout << DFS(sx, sy, d1, left_dir) << " " << DFS(sx, sy, d2, right_dir)
        << " " << BFS() << endl;
    }
    return 0;
}

