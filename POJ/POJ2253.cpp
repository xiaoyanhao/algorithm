# include <iostream>
# include <cstdio>
# include <cstring>
# include <iomanip>
# define inf 20
using namespace std;
int d[110][110];
int main() {
	int n, i, j, k, m, time;
	while (cin >> n && n) {
		memset(d, inf, sizeof(d));
		for (i = 1; i <= n; i++) {
			cin >> m;
			for (k = 1; k <= m; k++) {
				cin >> j >> time;
	        	d[i][j] = time;
			}
		}
		for (k = 1; k <= n; k++) {
			for (i = 1; i <= n; i++) {
				for (j = 1; j <= n; j++) {
					if (i != j && d[i][k] + d[k][j] < d[i][j]) { ////i!=j是因为无向图的顶点(一般)不存在环 
						d[i][j] = d[i][k] + d[k][j];
					}
				}
			}
		}
		int maxlength, flag_source, min_in_max = inf;
		for (i = 1; i <= n; i++) {
			maxlength = 0;
			for (j = 1; j <= n; j++) {
				if (i != j && maxlength < d[i][j]) {
					maxlength = d[i][j];
				}
			}
			if (min_in_max > maxlength) {
				min_in_max = maxlength;
				flag_source = i; 
			}
		}
		if (min_in_max < inf) {
			cout << flag_source << ' ' << min_in_max << endl;
		} else {
			cout << "disjoint" << endl;
		}
	} 
    return 0;
}

