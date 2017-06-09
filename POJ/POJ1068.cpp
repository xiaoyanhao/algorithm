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
int main() {
	int t, n, i, j, k, p, ans[1002];
	cin >> t;
	while (t--) {
		memset(ans, 0, sizeof(ans));
		string s = "\0";
		cin >> n;
		j = 0;
		for (i = 0; i < n; i++) {
			cin >> p;
			for (; j < p; j++) {
				s += '(';
			}
			s += ')';
		}
		for (i = 0, j = 0; i < s.size(); i++) {
			if (s[i] == ')') {
				if (s[i - 1] == '(') {
					ans[++j] = 1;
				} else {
					int right = 1;
					ans[++j]++;
					for (k = i - 1; k >= 0; k--) {
						if (right == 0) {
							break;
						}
						if (s[k] == ')') {
							right++;
							ans[j]++;
						} else {
							right--;
						}
					}
				}
			}
		}
		for (i = 1; i <= j; i++) {
			cout << ans[i] << " ";
		}
		cout << endl;
	} 
    return 0;
}

