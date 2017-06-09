#include <iostream>
using namespace std;
int dis[105][105], p[105];

int Prim(int n) {
    int i, j, k, ans = 0;
    for (i = 1; i < n; i++) {
        p[i] = 0;
    }
    p[0] = 1;
    for (i = 0; i < n - 1; i++) {
        int temp = 1000000, x, y;
        for (j = 0; j < n; j++) {
            if (p[j]) {
                for (k = 0; k < n; k++) {
                    if (!p[k] && temp > dis[j][k]) {
                        temp = dis[j][k];
                        x = j;
                        y = k;
                    }
                }
            }
        }
        p[x] = p[y] = 1;
        ans += temp;
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i, j;
        cin >> n;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                cin >> dis[i][j];
            }
        }
        cout << Prim(n) << endl;
    }
    return 0;
}



// 加速改进版
#include <iostream>

using namespace std;

#define MAX_COST 10001
#define MAXN 1001

bool U[MAXN];
short G[MAXN][MAXN];
short lowcost[MAXN];
short closest[MAXN];

int Prim(int n) {
    for (int i = 0; i < n; i++) {
        closest[i] = 0;
        lowcost[i] = G[0][i];
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
                closest[j] = x;
            }
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

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
