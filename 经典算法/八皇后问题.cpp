/* 在8X8格的国际象棋上摆放八个皇后，使其不能互相攻击，即任意两个皇后都不能处于同一行、同一列或同一斜线上，问有多少种摆法。*/
# include <iostream>
# include <cstring>
# define n 8
using namespace std;
int tot = 0, vis[3][n * n + 2], c[n + 2];
void search(int cur) {
	int i, j;
	if (cur == n) {
		tot++;
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (c[i] == j) {
					cout << "Q ";
				} else {
					cout << "* ";
				}
			}
			cout << endl; 
		}
		cout << endl;
	} else {
		for (i = 0; i < n; i++) {
			if (!vis[0][i] && !vis[1][cur + i] && !vis[2][cur - i + n]) {
				c[cur] = i;
				vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = 1;
				search(cur + 1);
				vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = 0;
			}
		}
	}
}
int main() {
	int i;
	memset(vis, 0, sizeof(vis));
	search(0);
	cout << tot << endl;
	return 0;
}
