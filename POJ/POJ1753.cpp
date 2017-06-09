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
int map[4][4], step;
bool flag = false;
void flip(int row, int col) {
	map[row][col] = !map[row][col];
	if (row > 0) {
		map[row - 1][col] = !map[row - 1][col];
	}
	if (row < 3) {
		map[row + 1][col] = !map[row + 1][col];
	}
	if (col > 0) {
		map[row][col - 1] = !map[row][col - 1];
	}
	if (col < 3) {
		map[row][col + 1] = !map[row][col + 1];
	}
}
bool judge() {
	int i, j;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (map[i][j] != map[0][0]) {
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
	if (flag || row == 4) {
		return;
	}
	flip(row, col);
	if (col < 3) {
		dfs(row, col + 1, depth + 1);
	} else {
		dfs(row + 1, 0, depth + 1);
	}
	flip(row, col);
	if (col < 3) {
		dfs(row, col + 1, depth);
	} else {
		dfs(row + 1, 0, depth);
	}
	return;
}
int main() {
	string s;
	int i, j, k;
	for (i = 0; i < 4; i++) {
		cin >> s;
		for (j = 0; j < 4; j++) {
			if (s[j] == 'b') {
				map[i][j] = 0;
			} else {
				map[i][j] = 1;
			}
		}
	} 
	for (step = 0; step <= 16; step++) {
		dfs(0, 0, 0);
		if (flag) {
			break;
		}
	} 
	if (flag) {
		cout << step << endl;
	} else {
		cout << "Impossible" << endl;
	}
    return 0;
}

