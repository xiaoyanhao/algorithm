# include <iostream>
# include <cstdio>
# include <cstdlib>
# include <cmath>
# include <cstring>
# include <string>
# include <iomanip>
# include <stack>
# include <algorithm>
using namespace std;
int map[105][105], robots[105], x[105], y[105], a, b;
void move(int num, int repetition, bool& crash) {
	int i, j, k;
	if (robots[num] == 1) {
		for (i = x[num] + 1; i <= repetition + x[num]; i++) {
			if (i == 0 || i == a + 1) {
				cout << "Robot " << num << " crashes into the wall" << endl;
				crash = true;
				return;
			}
			if (map[i][y[num]] != 0) {
				cout << "Robot " << num << " crashes into robot " << map[i][y[num]] << endl;
				crash = true;
				return;
			}
		}
		map[x[num] + repetition][y[num]] = map[x[num]][y[num]];
		map[x[num]][y[num]] = 0;
		x[num] += repetition;
	} else if (robots[num] == 2) {
		for (i = y[num] - 1; i >= y[num] - repetition; i--) {
			if (i == 0 || i == b + 1) {
				cout << "Robot " << num << " crashes into the wall" << endl;
				crash = true;
				return;
			}
			if (map[x[num]][i] != 0) {
				cout << "Robot " << num << " crashes into robot " << map[x[num]][i] << endl;
				crash = true;
				return;
			} 
		} 
		map[x[num]][y[num] - repetition] = map[x[num]][y[num]];
		map[x[num]][y[num]] = 0;
		y[num] -= repetition;
	} else if (robots[num] == 3) {
		for (i = x[num] - 1; i >= x[num] - repetition; i--) {
			if (i == 0 || i == a + 1) {
				cout << "Robot " << num << " crashes into the wall" << endl;
				crash = true;
				return;
			}
			if (map[i][y[num]] != 0) {
				cout << "Robot " << num << " crashes into robot " << map[i][y[num]] << endl;
				crash = true;
				return;
			}
		}
		map[x[num] - repetition][y[num]] = map[x[num]][y[num]];
		map[x[num]][y[num]] = 0;
		x[num] -= repetition;
	} else {
		for (i = y[num] + 1; i <= y[num] + repetition; i++) {
			if (i == 0 || i == b + 1) {
				cout << "Robot " << num << " crashes into the wall" << endl;
				crash = true;
				return;
			}
			if (map[x[num]][i] != 0) {
				cout << "Robot " << num << " crashes into robot " << map[x[num]][i] << endl;
				crash = true;
				return;
			} 
		} 
		map[x[num]][y[num] + repetition] = map[x[num]][y[num]];
		map[x[num]][y[num]] = 0;
		y[num] += repetition;
	}
}
int main() {
	int t, n, m, i, j, k, xx, yy, num, repetition;
	char action, dir;
	cin >> t;
	while (t--) {
		memset(map, 0, sizeof(map));
		memset(robots, 0, sizeof(robots));
		memset(x, 0, sizeof(x));
		memset(y, 0, sizeof(y));
		cin >> a >> b;
		cin >> n >> m;
		for (i = 1; i <= n; i++) {
			cin >> xx >> yy >> dir;
			map[xx][yy] = i;
			x[i] = xx;
			y[i] = yy;
			if (dir == 'E') {
				robots[i] = 1;
			} else if (dir == 'S') {
				robots[i] = 2;
			} else if (dir == 'W') {
				robots[i] = 3;
			} else if (dir == 'N') {
				robots[i] = 4;
			}
		} 
		bool crash = false;
		for (j = 1; j <= m; j++) {
			cin >> num >> action >> repetition;
			if (crash) {
				continue;
			}
			if (action == 'L') {
				for (k = 1; k <= repetition; k++) {
					robots[num]--;
					if (robots[num] == 0) {
						robots[num] = 4;
					}
				}
			} else if (action == 'R') {
				for (k = 1; k <= repetition; k++) {
					robots[num]++;
					if (robots[num] == 5) {
						robots[num] = 1;
					}
				}
			} else {
				move(num, repetition, crash);
			}
		}
		if (!crash) {
			cout << "OK" << endl;
		}
	}
    return 0;
}

