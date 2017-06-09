# include <iostream>
# include <cstring>
# include <string>
using namespace std;
const int inf = 100002;
int dist[102][102], n;

int prim() {
	int s = 1;
	int m = 1;
	bool u[102];
	int low_dist[102];
	int min_w;
	int total_w = 0;
	int flag, i;
	memset(u, false, sizeof(u));
	u[s] = true;
	for (i = 1; i <= n; i++) {
		low_dist[i] = inf;
	}
	while (m < n) {
		min_w = inf;
		for (i = 2; i <= n; i++) {
			if (!u[i] && low_dist[i] > dist[s][i]) {
				low_dist[i] = dist[s][i];
			}
			if (!u[i] && min_w > low_dist[i]) {
				min_w = low_dist[i];
				flag = i;
			}
		}
		s = flag;
		u[s] = true;
		total_w += min_w;
		m++;
	}
	return total_w;
}

int main() {
	ios::sync_with_stdio(false);
	int i, j, k;
	while (cin >> n) {
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				cin >> dist[i][j];
			}
		}
		cout << prim() << endl;
	}
	return 0;
}

