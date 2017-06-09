#include <iostream>
#include <cstdio>

using namespace std;

#define MAX_N 1001
#define MAX_LEN 1000001

int dis[MAX_N][MAX_N];

int Floyd(int n, int s, int t) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dis[i][j] > dis[i][k] + dis[k][j]) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }

    return dis[s][t] == MAX_LEN ? -1 : dis[s][t];
}

int main() {
    int n, m, s, t;

    cin >> n >> m >> s >> t;

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

    cout << Floyd(n, s, t) << endl;

    return 0;
}
