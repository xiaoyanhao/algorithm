# include <iostream>
# include <cstring>
# include <string>
using namespace std;
const int inf = 10;
int dist[2005][2005], n;
string s[2005];

int weight(int i, int j) {
	int count = 0, k;
	for (k = 0; k < 7; k++) {
		if (s[i][k] != s[j][k]) {
			count++;
		}
	}
	return count;
}

int prim() {
	int s = 1;
	int m = 1;
	bool u[2005];
	int total_w = 0;
	int min_w;
	int flag, i, j;
	int low_dis[2005];
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
	while (cin >> n && n) {
		for (i = 1; i <= n; i++) {
			cin >> s[i];
		}
		for (i = 1; i < n; i++) {
			for (j = i + 1; j <= n; j++) {
				dist[i][j] = dist[j][i] = weight(i, j);
			}
		}
		cout << "The highest possible quality is 1/" << prim() << '.' << endl;
	}
	return 0;
}
