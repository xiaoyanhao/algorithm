#include <iostream>
#include <cstdio>

using namespace std;

#define MAX_N 1001
#define MAX_LEN 1000001

bool U[MAX_N];
int G[MAX_N][MAX_N];
int lowcost[MAX_N];

int Dijkstra(int n, int s, int t) {
    for (int i = 1; i <= n; i++) {
        lowcost[i] = G[s][i];
        U[i] = false;
    }

    U[s] = true;

    for (int i = 1; i < n; i++) {
        int min_cost = MAX_LEN;
        int x = 0;

        for (int j = 1; j <= n; j++) {
            if (!U[j] && lowcost[j] < min_cost) {
                min_cost = lowcost[j];
                x = j;
            }
        }

        U[x] = true;

        for (int j = 1; j <= n; j++) {
            if (!U[j] && G[x][j] + lowcost[x] < lowcost[j]) {
                lowcost[j] = G[x][j] + lowcost[x];
            }
        }
    }

    return lowcost[t] == MAX_LEN ? -1 : lowcost[t];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, s, t;

    cin >> n >> m >> s >> t;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            G[i][j] = G[j][i] = MAX_LEN;
        }
        G[i][i] = 0;
    }

    for (int i = 1; i <= m; i++) {
        int u, v, length;
        cin >> u >> v >> length;
        if (G[u][v] > length) {
            G[u][v] = G[v][u] = length;
        }
    }

    cout << Dijkstra(n, s, t) << endl;

    return 0;
}
