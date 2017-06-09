# include <iostream>
# include <cstdio>
# include <cstring>
# include <queue>
using namespace std;
struct Edge{
	int dest;
	int value;
	Edge* link;
}*edge[10010], tmp[10010];
int p[10010], l[10010], MIN = 99999999;
void addedge(int i, int j, int v, int index) {
	tmp[index].dest = j;
	tmp[index].value = v;
	tmp[index].link = edge[i];
	edge[i] = tmp + index;
}
void spfa(int s, int left, int right, int n) {
	bool vis[10010];
	int d[10010], i, j, k;
	memset(vis, false, sizeof(false));
	for (i = 1; i <= n + 1; i++) {
		d[i] = 99999999;
	}
	vis[s] = true;
	d[s] = 0;
	queue<int> Q;
	Q.push(s);
	while (!Q.empty()) {
		k = Q.front();
		Q.pop();
		vis[k] = false;
		for (Edge* x = edge[k]; x; x = x->link) {
			if (d[x->dest] > d[k] + x->value && l[k] >= left && l[k] <= right && l[x->dest] >= left && l[x->dest] <= right) {
				d[x->dest] = d[k] + x->value;
				if (!vis[x->dest]) {
					vis[x->dest] = true;
					Q.push(x->dest);
				}
			}
		}
	}
	for (i = 1; i <= n; i++) {
		if (d[i] + p[i] < MIN) {
			MIN = d[i] + p[i];
		}
	}
}
int main() {
	int m, n, x, t, v, i, j, k, index = -1;
	cin >> m >> n;
	for (i = 1; i <= n; i++) {
		cin >> p[i] >> l[i] >> x;
		for (j = 1; j <= x; j++) {
			cin >> t >> v;
			addedge(i, t, v, ++index);
		}
	}
	for (i = l[1] - m; i <= l[1]; i++) {
		spfa(1, i, i + m, n);
	}
	cout << MIN << endl;
    return 0;
}

