#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX_N 100001
#define MAX_LEN 100000001

struct Edge {
    int dest;
    int cost;
};

bool U[MAX_N];
int lowcost[MAX_N];
vector<Edge> G[MAX_N];

int SPFA(int n, int s, int t) {
    for (int i = 1; i <= n; i++) {
        U[i] = false;
        lowcost[i] = MAX_LEN;
    }

    queue<int> Q;
    Q.push(s);
    U[s] = true;
    lowcost[s] = 0;

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        U[u] = false;
        int len = G[u].size();
        for (int i = 0; i < len; i++) {
            int v = G[u][i].dest;
            int cost = G[u][i].cost;
            if (lowcost[v] > lowcost[u] + cost) {
                lowcost[v] = lowcost[u] + cost;
                if (!U[v]) {
                    U[v] = true;
                    Q.push(v);
                }
            }
        }
    }

    return lowcost[t];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, s, t, u, v;
    Edge e;

    cin >> n >> m >> s >> t;

    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> e.cost;
        e.dest = v;
        G[u].push_back(e);
        e.dest = u;
        G[v].push_back(e);
    }

    cout << SPFA(n, s, t) << endl;

    return 0;
}
