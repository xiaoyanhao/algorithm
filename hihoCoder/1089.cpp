#include <iostream>
#include <cstdio>

using namespace std;

#define MAX_N 101
#define MAX_LEN 100001

int dis[MAX_N][MAX_N];

void Floyd(int n) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dis[i][j] > dis[i][k] + dis[k][j]) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
}

int main() {
    int n, m;

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            dis[i][j] = dis[j][i] = MAX_LEN;
        }
        dis[i][i] = 0;
    }

    for (int i = 1; i <= m; i++) {
        int u, v, length;
        cin >> u >> v >> length;
        if (dis[u][v] > length) {
            dis[u][v] = dis[v][u] = length;
        }
    }

    Floyd(n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << dis[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
