# include <iostream>
# include <cstring>
# include <queue>
using namespace std;
int l, r, c, sx, sy, sz, vis[35][35][35], dir[6][3] =
{{0, -1, 0}, {-1, 0, 0}, {0, 1, 0}, {1, 0, 0}, {0, 0, 1}, {0, 0, -1}};
char map[35][35][35];
struct Node{
    int z, x, y, step;
    Node(int z1, int x1, int y1, int step1): z(z1), x(x1), y(y1), step(step1) {
    }
};

int BFS() {
    Node node(sz, sx, sy, 0);
    queue<Node> Q;
    Q.push(node);
    while (!Q.empty()) {
        node = Q.front();
        Q.pop();
        if (map[node.z][node.x][node.y] == 'E') {
            return node.step;
        }
        vis[node.z][node.x][node.y] = 1;
        for (int i = 0; i < 6; i++) {
            int nx = node.x + dir[i][0];
            int ny = node.y + dir[i][1];
            int nz = node.z + dir[i][2];
            if (nx >= 0 && nx < r && ny >= 0 && ny < c && nz >= 0 && nz < l && !vis[nz][nx][ny] && map[nz][nx][ny] != '#') {
                vis[nz][nx][ny] = 1;
                Node next(nz, nx, ny, node.step + 1);
                Q.push(next);
            }
        }
    }
    return -1;
}

int main() {
    int i, j, k;
    while (cin >> l >> r >> c && l && r && c) {
        memset(vis, 0, sizeof(vis));
        for (i = 0; i < l; i++) {
            for (j = 0; j < r; j++) {
                cin >> map[i][j];
                for (k = 0; k < c; k++) {
                    if (map[i][j][k] == 'S') {
                        sx = j;
                        sy = k;
                        sz = i;
                    }
                }
            }
        }
        int ans = BFS();
        if (ans == -1) {
            cout << "Trapped!" << endl;
        } else {
            cout << "Escaped in " << ans << " minute(s)." << endl;
        } 
    }
    return 0;
}

