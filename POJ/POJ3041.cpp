# include <iostream>
# include <cstring>
using namespace std;
int n, k, V1, V2, ans, link[505];
bool map[505][505], vis[505];

bool dfs(int x) {
    for (int y = 1; y <= V2; y++) {
        if (map[x][y] && !vis[y]) {
            vis[y] = true;
            if (link[y] == 0 || dfs(link[y])) {
                link[y] = x;
                return true;
            }
        }
    }
    return false;
} 

void Hungary() {
    for (int x = 1; x <= V1; x++) {
        memset(vis, false, sizeof(vis));
        if (dfs(x)) {
            ans++;
        }
    }
}

int main() {
    cin >> n >> k;
    V1 = V2 = n;
    int x, y;
    for (int i = 1; i <= k; i++) {
        cin >> x >> y;
        map[x][y] = true;
    }
    Hungary();
    cout << ans << endl;
    return 0;
}

