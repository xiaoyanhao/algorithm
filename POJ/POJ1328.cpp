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
# define MIN -1<<30
using namespace std;
struct node{
	double right;
	double left;
}a[1005], b;
bool cmp(node x, node y) {
	return x.left < y.left;
}
int main() {
	int i, j, k, n, t = 0;
	double x, y, d;
	while (cin >> n >> d && n && d) {
		double tmp; 
		bool flag = false;
		for (i = 0; i < n; i++) {
			cin >> x >> y;
			if (y > d) {
				flag = true;
			}
			tmp = sqrt(d * d - y * y);
			a[i].left = x - tmp;
			a[i].right = x + tmp;
		}
		cout << "Case " << ++t << ": ";
		if (flag) {
			cout << "-1" << endl;
			continue;
		}
		sort(a, a + n, cmp);
		b = a[0];
		int count = 1;
		for (i = 1; i < n; i++) {
			if (a[i].left > b.right) {
				count++;
				b = a[i];
			}
			if (a[i].right <= b.right) {
				b = a[i];
			}
		}
		cout << count << endl;
	}
    return 0;
}

