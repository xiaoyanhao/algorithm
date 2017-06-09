# include <iostream>
# include <queue>
# include <cstring>
using namespace std;

int a, b, vis[10001], t[4];
bool prime[10001];

void isPrime() {
    int i, j;
    for (i = 1000; i <= 10000; i++) {
        for (j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                prime[i] = 0;
                break;
            }
        }
        if (j * j > i) {
            prime[i] = 1;
        }
    }
}

struct Node {
    int num, step;
    Node(int n, int s): num(n), step(s) {
    }
};

int BFS() {
    queue<Node> Q;
    Node node(a, 0);
    memset(vis, 0, sizeof(vis));
    vis[a] = 1;
    Q.push(node);
    while (!Q.empty()) {
        node = Q.front();
        Q.pop();
        t[0] = node.num / 1000;
        t[1] = node.num % 1000 / 100;
        t[2] = node.num % 100 / 10;
        t[3] = node.num % 10;
        if (node.num == b) {
            return node.step;
        }
        for (int i = 0; i < 4; i++) {
            int temp = t[i];
            for (int j = 0; j < 10; j++) {
                if (j != temp) {
                    t[i] = j;
                    int vtemp = t[0] * 1000 + t[1] * 100 + t[2] * 10 + t[3];
                    if (!vis[vtemp] && prime[vtemp]) {
                        vis[vtemp] = 1;
                        Node next(vtemp, node.step + 1);
                        Q.push(next);
                    }
                } 
            }
            t[i] = temp;
        }
    }
    return -1;
}

int main() {
    int t;
    cin >> t;
    isPrime();
    while (t--) {
        cin >> a >> b;
        int ans = BFS();
        if (ans == -1) {
            cout << "Impossible" << endl;
        } else {
            cout << ans << endl;
        }
    }
    return 0;
}

