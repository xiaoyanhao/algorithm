# include <iostream>
# include <cstdio>
# include <cstring>
# include <iomanip>
# include <queue> 
# include <map>
# include <string>
# define inf 99999999 
using namespace std;
double d[35][35];
int main() {
	int n, i, j, k, m, cases = 0;
	double r;
	string name, name2;
	while (cin >> n && n) {
		map<string, int> currency;
		memset(d, 0, sizeof(d));
		for (i = 1; i <= n; i++) {
			cin >> name;
			currency[name] = i;
			d[i][i] = 1;
		}
		cin >> m;
		for (i = 1; i <= m; i++) {
			cin >> name >> r >> name2;
			d[currency[name]][currency[name2]] = r;
		}
		for (k = 1; k <= n; k++) {
			for (i = 1; i <= n; i++) {
				for (j = 1; j <= n; j++) {
					if (d[i][j] < d[i][k] * d[k][j]) {
						d[i][j] = d[i][k] * d[k][j];
					}
				}
			}
		}
		bool flag = false;
		for (i = 1; i <= n; i++) {
			if (d[i][i] > 1) {
				flag = true;
				break;
			}
		}
		if (flag) {
			cout << "Case " << ++cases << ": Yes" << endl;
		} else {
			cout << "Case " << ++cases << ": No" << endl;
		}
	} 
    return 0;
}

