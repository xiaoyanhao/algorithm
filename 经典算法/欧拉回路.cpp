# include <iostream>
# include <iomanip> 
# include <cstdio>
# include <cstring>
# include <string>
# include <cmath>
# include <algorithm>
# include <cstdlib>
# include <stack>
# include <vector>
using namespace std;
struct Edge{
	int e;
	bool vis;
};
vector<Edge> f[10005];
stack<int> stk;
void euler(int x) {
	for (int i = 0; i < f[x].size(); i++) {
		if (!f[x][i].vis) {
			f[x][i].vis = true;
			euler(f[x][i].e);
		}
	}
	stk.push(x);
}
int main() {
	int n, m, i, j, k, s, t, total = 0;
	Edge tmp;
	tmp.vis = false;
	cin >> n;
	while (n--) {
		cin >> m >> s;
		for (i = 1; i <= m; i++) {
			cin >> tmp.e;
			f[s].push_back(tmp);
			s = tmp.e;
		}
		total += m;
	} 
	cout << total << " ";
	euler(1);
	while (!stk.empty()) {
		cout << stk.top() << " ";
		stk.pop();
	}
	cout << endl;
	return 0;
}

