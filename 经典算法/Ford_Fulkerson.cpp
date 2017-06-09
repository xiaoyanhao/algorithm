/* 网络的最大流问题：1、发点的净流出量和收点的净流入量必相等；2、每一个中间点的流入量和流出量的代数和为零；
3、每一个弧上的流量不能超过它的最大通过能力（即容量） */ 
# include <iostream>
# include <queue>
# include <cstring>
using namespace std;
struct Edge{
	int dest;
	Edge* link;
}*edge[500], tmp[500];
int G[250][250];
void addedge(int i, int j, int index) {
	tmp[index].dest = j;
	tmp[index].link = edge[i];
	edge[i] = tmp + index;
}
int find_path(int n, int s, int t, int* pre) {
	queue<int>q;
	int mark[500];
	memset(mark, 0, sizeof(mark));
	mark[s] = 1, q.push(s); 
	while (!q.empty()) {
		int x = q.front();
		for (Edge* l = edge[x]; l; l = l->link) {
			if (G[x][l->dest] > 0 && mark[l->dest] == 0) {
				mark[l->dest] = 1;
				pre[l->dest] = x;
				if (l->dest == t) {
					return 1;
				}
				q.push(l->dest);
			}
		}
		q.pop();
	}
	return 0;
}
int Ford_Fulkerson(int n, int s, int t, int& F) {
	int i, min = 1000000000;
	int pre[250];
	if (find_path(n, s, t, pre) == 0) {
		return 0;
	}
	for (i = t; i != s; i = pre[i]) {
		if (G[pre[i]][i] < min) {
			min = G[pre[i]][i];
		}
	}
	for (i = t; i != s; i = pre[i]) {
		G[pre[i]][i] -= min;
		G[i][pre[i]] += min;
	}
	F += min;
	return 1;
} 
int main() {
	int n, m, si, ei, ci, i;
	while (cin >> n >> m) {
		for (i = 0; i < n; i++) {
			cin >> si >> ei >> ci;
			addedge(si, ei, i);
			G[si][ei] = ci;
		}
		int F = 0;
		while(Ford_Fulkerson(n, 1, m, F));
		cout << F << endl;
	}
	return 0;
} 
