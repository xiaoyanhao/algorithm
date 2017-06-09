#include <iostream>

using namespace std;

#define MAX_COST 10001
#define MAXN 1001

bool U[MAXN];
short G[MAXN][MAXN];
short lowcost[MAXN];
// short closest[MAXN];

int Prim(int n) {
    for (int i = 0; i < n; i++) {
        // closest[i] = 0;
        lowcost[i] = G[0][i];
        U[i] = false;
    }

    int ans = 0;
    U[0] = true; // 加入第一个点

    for (int i = 0; i < n - 1; i++) { // 加入n-1条边
        int min_cost = MAX_COST;
        int x = 0; // 最新加入集合U的点

        for (int j = 1; j < n; j++) {
            if (!U[j] && lowcost[j] < min_cost) {
                min_cost = lowcost[j];
                x = j;
            }
        }

        U[x] = true;
        ans += min_cost;

        // 更新所有不在集合U中的点到集合U的最近点
        for (int j = 1; j < n; j++) {
            if (!U[j] && G[x][j] < lowcost[j]) {
                lowcost[j] = G[x][j];
                // closest[j] = x;
            }
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> G[i][j];
        }
    }

    cout << Prim(n) << endl;

    return 0;
}
