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
struct chess{
	char type;
	char col;
	int row;
	int priority;
}black[70], white[70];
bool cmp_b(chess x, chess y) {
	if (x.priority == y.priority) {
		return x.row > y.row;
	} else {
		return x.priority > y.priority;
	}
}
bool cmp_w(chess x, chess y) {
	if (x.priority == y.priority) {
		return x.row < y.row;
	} else {
		return x.priority > y.priority;
	}
}
int main() {
	int i, j, k, index_b = -1, index_w = -1;
	string s;
	for (i = 17; i >= 1; i--) {
		cin >> s;
		if (i % 2 == 0) {
			for (j = 0; j < s.size(); j++) {
				if ((j - 2) % 4 == 0) {
					if (s[j] >= 'a' && s[j] <= 'z') {
						black[++index_b].type = s[j] - ('a' - 'A');
						black[index_b].row = i / 2;
						black[index_b].col = 'a' + (j - 2) / 4;
						if (black[index_b].type == 'K') {
							black[index_b].priority = 5;
						} else if (black[index_b].type == 'Q') {
							black[index_b].priority = 4;
						} else if (black[index_b].type == 'R') {
							black[index_b].priority = 3;
						} else if (black[index_b].type == 'B') {
							black[index_b].priority = 2;
						} else if (black[index_b].type == 'N') {
							black[index_b].priority = 1;
						} else {
							black[index_b].priority = 0;
						}
					}
					if (s[j] >= 'A' && s[j] <= 'Z') {
						white[++index_w].type = s[j];
						white[index_w].row = i / 2;
						white[index_w].col = 'a' + (j - 2) / 4;
						if (white[index_w].type == 'K') {
							white[index_w].priority = 5;
						} else if (white[index_w].type == 'Q') {
							white[index_w].priority = 4;
						} else if (white[index_w].type == 'R') {
							white[index_w].priority = 3;
						} else if (white[index_w].type == 'B') {
							white[index_w].priority = 2;
						} else if (white[index_w].type == 'N') {
							white[index_w].priority = 1;
						} else {
							white[index_w].priority = 0;
						}
					}
				}
			}
		}
	}
	sort(black, black + index_b + 1, cmp_b);
	sort(white, white + index_w + 1, cmp_w);
	cout << "White: ";
	for (i = 0; i <= index_w; i++) {
		if (i == index_w) {
			if (white[i].type == 'P') {
				cout << white[i].col << white[i].row;
			} else {
				cout << white[i].type << white[i].col << white[i].row;
			}
		} else {
			if (white[i].type == 'P') {
				cout << white[i].col << white[i].row << ",";
			} else {
				cout << white[i].type << white[i].col << white[i].row << ",";
			}
		}
	}
	cout << endl << "Black: ";
	for (i = 0; i <= index_b; i++) {
		if (i == index_b) {
			if (black[i].type == 'P') {
	     		cout << black[i].col << black[i].row;	
			} else {
				cout << black[i].type << black[i].col << black[i].row;
			}
		} else {
			if (black[i].type == 'P') {
				cout << black[i].col << black[i].row << ",";
			} else {
				cout << black[i].type << black[i].col << black[i].row << ",";
			}
		}
	}
	cout << endl;
    return 0;
}

