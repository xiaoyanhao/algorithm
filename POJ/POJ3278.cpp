# include <iostream>
# include <cstring>
# include <queue>
using namespace std;
int n, k, vis[200005];
struct Node {
    int x, step;
    Node(int x1, int step1): x(x1), step(step1) {
    }
};

int BFS() {
    Node node(n, 0);
    queue<Node> Q;
    Q.push(node);
    while (!Q.empty()) {
        node = Q.front();
        Q.pop();
        if (node.x == k) {
            return node.step;
        }
        vis[node.x] = 1;
        int x1 = node.x - 1;
        int x2 = node.x + 1;
        int x3 = node.x * 2;
        if (x1 <= 100000 && !vis[x1]) {
            vis[x1] = 1;
            Node next(x1, node.step + 1);
            Q.push(next);
        }
        if (x2 > 0 && !vis[x2]) {
            vis[x2] = 1;
            Node next(x2, node.step + 1);
            Q.push(next); 
        }
        if (x3 <= 100000 && !vis[x3]) {
            vis[x3] = 1;
            Node next(x3, node.step + 1);
            Q.push(next);
        }
    }
    return 0;
}

int main() {
    cin >> n >> k;
    memset(vis, 0, sizeof(vis));
    cout << BFS() << endl;
    return 0;
}

