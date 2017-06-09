# include <iostream>
# include <cstring>
# include <string>
using namespace std;
const int inf = 65540;
int dist[502][502], n;

int prim() {
	int s = 1;
	int m = 1;
	bool u[502];
	int max_in_min = 0;
	int min_w;
	int flag, i, j;
	int low_dis[502];
	memset(u, false, sizeof(u));
	u[s] = true;
	for (i = 1; i <= n; i++) {
		low_dis[i] = inf;
	}
	while (m < n) {
		min_w = inf;
		for (j = 2; j <= n; j++) {
			if (!u[j] && low_dis[j] > dist[s][j]) {
				low_dis[j] = dist[s][j];
			}
			if (!u[j] && min_w > low_dis[j]) {
				min_w = low_dis[j];
				flag = j;
			}
		}
		if (max_in_min < min_w) {
			max_in_min = min_w;
		}
		s = flag;
		u[s] = true;
		m++;
	}
	return max_in_min;
}

int main() {
	ios::sync_with_stdio(false);
	int i, j, k, t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				cin >> dist[i][j];
			}
		}
		
		cout << prim() << endl;
	}
	return 0;
}
