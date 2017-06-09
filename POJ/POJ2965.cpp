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
using namespace std;
int map[6][6] = {0}, step;
bool flag = false;
int rx[20], ry[20];
void switching(int row, int col) {
	for (int i = 1; i <= 4; i++) {
		map[row][i] = !map[row][i];
		map[i][col] = !map[i][col];
	}
	map[row][col] = !map[row][col];
}
bool judge() {
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			if (map[i][j] == 0) {
				return false;
			}
		}
	}
	return true;
}
void dfs(int row, int col, int depth) {
	if (depth == step) {
		flag = judge();
		return;
	}
	if (flag || row == 5) {
		return;
	}
	switching(row, col);
	rx[depth] = row;
	ry[depth] = col;
	if (col < 4) {
		dfs(row, col + 1, depth + 1);
	} else {
		dfs(row + 1, 1, depth + 1);
	}
	switching(row, col);
	if (col < 4) {
		dfs(row, col + 1, depth);
	} else {
		dfs(row + 1, 1, depth);
	}
	return;
}
int main() {
	string s;
	int i, j, k;
	for (i = 1; i <= 4; i++) {
		cin >> s;
		for (j = 1; j <= 4; j++) {
			if (s[j - 1] == '+') {
				map[i][j] = 0;
			} else {
				map[i][j] = 1;
			}
		}
	} 
	for (step = 0; step <= 16; step++) {
		//memset(map2, false, sizeof(map2));
		dfs(1, 1, 0);
		if (flag) {
			break;
		}
	} 
	if (flag) {
		cout << step << endl;
		for (i = 0; i < step; i++) {
			cout << rx[i] << " " << ry[i] << endl;
		}
	}
    return 0;
}

