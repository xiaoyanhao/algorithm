# include <iostream>
# include <queue>
# include <cstring>
# include <string>
using namespace std;

int row, col, direction[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int edge[102][102], mark[52][52], num;
bool visited[52][52];
char map[52][52];
struct Node {
    int x;
    int y;
    int step;
    Node(int x1, int y1, int step1): x(x1), y(y1), step(step1) {
    }
};

void BFS(int i, int j) {
    memset(visited, false, sizeof(visited));
    Node node(i, j, 0);
    queue<Node> Q;
    Q.push(node);
    while (!Q.empty()) {
        node = Q.front();
        Q.pop();
        if (mark[node.x][node.y]) {
            edge[mark[i][j]][mark[node.x][node.y]] = node.step;
        }
        visited[node.x][node.y] = true;
        for (int k = 0; k < 4; k++) {
            int x = node.x + direction[k][0];
            int y = node.y + direction[k][1];
            if (!visited[x][y] && map[x][y] != '#' && x >= 1 && x <= row && y >= 1 && y <= col) {
                visited[x][y] = true;
                Node next(x, y, node.step + 1);
                Q.push(next);
            } 
        }
    }
}

int prim() {
    int s = 1, total = 0, low_dis[102], min_w, flag, i, j;
    bool u[102];
    for (i = 1; i <= num; i++) {
        low_dis[i] = 2600;
        u[i] = false; 
    }
    u[s] = true;
    for (i = 1; i < num; i++) {
        min_w = 2600;
        for (j = 2; j <= num; j++) {
            if (!u[j] && low_dis[j] > edge[s][j]) {
                low_dis[j] = edge[s][j]; 
            }
            if (!u[j] && min_w > low_dis[j]) {
                min_w = low_dis[j];
                flag = j;
            }
        }
        s = flag;
        u[s] = true;
        total += min_w;
    }
    return total;
}

int main() {
    int N, i, j;
    cin >> N;
    while (N--) {
        string tmp;
        char c;
        num = 0;
        memset(mark, 0, sizeof(mark));
        cin >> col >> row >> c;
        for (i = 1; i <= row; i++) {
            getline(cin, tmp);
            for (j = 1; j <= col; j++) {
                map[i][j] = tmp[j - 1];
                if (map[i][j] == 'S' || map[i][j] == 'A') {
                    mark[i][j] = ++num;
                }
            }
        }
        for (i = 1; i <= row; i++) {
            for (j = 1; j <= col; j++) {
                if (mark[i][j]) {
                    BFS(i, j);
                }
            }
        }
        cout << prim() << endl;
    }
    return 0;
}

