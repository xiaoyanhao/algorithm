# include <iostream>
# include <cstdio>
# include <cstdlib>
# include <cmath>
# include <cstring>
# include <string>
# include <iomanip>
# include <vector>
# include <stack>
# include <algorithm>
# define MAXINT 9999999
using namespace std;
struct Edge{
	int u, v, time;
}edge[5210]; 
bool Bellman_Ford(int n, int index) {
	int d[505], i, j;
	memset(d, MAXINT, sizeof(d));
	d[1] = 0;
	for (i = 1; i < n; i++) {
		for (j = 1; j <= index; j++) {
			if (d[edge[j].v] > d[edge[j].u] + edge[j].time) {
				d[edge[j].v] = d[edge[j].u] + edge[j].time;
			}
		}
	}
	for (i = 1; i <= index; i++) {
		if (d[edge[i].v] > d[edge[i].u] + edge[i].time) {
			return false;
		}
	} 
	return true;
}
int main() {
	int F, n, m, w, i, j, s, e, t;
	cin >> F;
	while (F--) {
		int index = 0;
		memset(edge, 0, sizeof(edge));
		cin >> n >> m >> w;
		for (i = 1; i <= m; i++) {
			cin >> s >> e >> t;
			edge[++index].u = s;
			edge[index].v = e;
			edge[index].time = t;
			edge[++index].u = e;
			edge[index].v = s;
			edge[index].time = t;
		}
		for (i = 1; i <= w; i++) {
			cin >> s >> e >> t;
			edge[++index].u = s;
			edge[index].v = e;
			edge[index].time = -t;
		}
		if (!Bellman_Ford(n, index)) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
    return 0;
}

