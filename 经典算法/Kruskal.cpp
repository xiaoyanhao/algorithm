#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_M 1000001
#define MAX_N 100001

struct Edge {
    int u, v, cost;

    bool operator<(const Edge& e) const {
        return cost < e.cost;
    }
};

int fa[MAX_N];
Edge E[MAX_M];

// 在并查集中查找x的祖先
int get_fa(int x) {
    return fa[x] == x ? x : fa[x] = get_fa(fa[x]);
}

int Kruscal(int n, int m) {
    // 初始化并查集
    for (int i = 0; i < n; i++) {
        fa[i] = i;
    }

    // 按照边权升序排序
    sort(E, E + m);

    int ans = 0;

    for (int i = 0; i < m; i++) {
        int u = E[i].u;
        int v = E[i].v;
        int u_fa = get_fa(u);
        int v_fa = get_fa(v);
        if (u_fa != v_fa) {
            ans += E[i].cost;
            fa[u_fa] = v_fa;
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> E[i].u >> E[i].v >> E[i].cost;
    }

    cout << Kruscal(n, m) << endl;

    return 0;
}
