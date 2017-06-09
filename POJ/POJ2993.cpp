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
char chess[70][70] = {
	"+---+---+---+---+---+---+---+---+",
	"|...|:::|...|:::|...|:::|...|:::|",
	"+---+---+---+---+---+---+---+---+",
	"|:::|...|:::|...|:::|...|:::|...|",
	"+---+---+---+---+---+---+---+---+",
	"|...|:::|...|:::|...|:::|...|:::|",
	"+---+---+---+---+---+---+---+---+",
	"|:::|...|:::|...|:::|...|:::|...|",
	"+---+---+---+---+---+---+---+---+",
	"|...|:::|...|:::|...|:::|...|:::|",
	"+---+---+---+---+---+---+---+---+",
	"|:::|...|:::|...|:::|...|:::|...|",
	"+---+---+---+---+---+---+---+---+",
	"|...|:::|...|:::|...|:::|...|:::|",
	"+---+---+---+---+---+---+---+---+",
	"|:::|...|:::|...|:::|...|:::|...|",
	"+---+---+---+---+---+---+---+---+"
};

int main() {
	string w, b;
	int i, j, k;
	getline(cin, w);
	getline(cin, b);
	for (i = 7; i < w.size();) {
		if (w[i] >= 'A' && w[i] <= 'Z') {
			chess[15 - 2 * (w[i + 2] - '0' - 1)][2 + 4 * (w[i + 1] - 'a')] = w[i];
			i += 4;
		}
		if (w[i] >= 'a' && w[i] <= 'z') {
			chess[15 - 2 * (w[i + 1] - '0' - 1)][2 + 4 * (w[i] - 'a')] = 'P';
			i += 3;
		}
		
	}
	for (i = 7; i < b.size();) {
		if (b[i] >= 'A' && b[i] <= 'Z') {
			chess[15 - 2 * (b[i + 2] - '0' - 1)][2 + 4 * (b[i + 1] - 'a')] = w[i] + 'a' - 'A';
			i += 4;
		}
		if (b[i] >= 'a' && b[i] <= 'z') {
			chess[15 - 2 * (b[i + 1] - '0' - 1)][2 + 4 * (b[i] - 'a')] = 'p';
			i += 3;
		}
	}
	for (i = 0; i <= 16; i++) {
		for (j = 0; j <= 32; j++) {
			cout << chess[i][j];
		}
		cout << endl; 
	}
	return 0;
} 
