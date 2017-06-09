//任意边权的单源最短路
# include <iostream>
# include <cstring>
using namespace std;
struct Edge{
	int dest;
	int value;
	Edge* link;
}*edge[1000], tmp[2000];
void Bellman_Ford(int s) {
	int D[1000];  //用于递推记录最短路长度 
	int P[1000];  //用于记录最短路
	memset(D, -1, sizeof(D));
	memset(P, -1, sizeof(P));
	for (Edge* x = edge[s]; x; x = x->link) {
		D[x->dest] = x->value;
		P[x->dest] = s;
	} 
	for (int k = 2; k < 1000; k++) {
		for (int i = 0; i < 1000; i++) {
			if (D[edge[i]->dest] < 0 || D[edge[i]->dest] > D[i] + edge[i]->value) {
				D[edge[i]->dest] = D[i] + edge[i]->value;
				P[edge[i]->dest] = i;
			}
		}
	}
	// s到ss的最短路为D[ss]。 
}

void spfa(int s){
	memset(vis, false, sizeof(vis));
	for (int i = 0; i <= n; i++) {
		d[i] = oo;
	}
	d[s] = 0;
	queue<int> Q;
	Q.push(s);
	used[s] = true;
	while (!Q.empty()) {
		int k = Q.front();
		Q.pop();
		for (Edge* x = edge[k]; x; x = x->dest) {
			if (d[x->dest] > d[k] + x->value) {
				d[x->dest] = d[k] + x->value;
				if (!vis[x->dest]) {
					vis[x->dest] = true;
					Q.push(x->dest);
				}
			}
		}
		vis[k] = false;
	}
}
int main() {
	
	return 0;
}
