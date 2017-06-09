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
int p, q, r, s, t, tmp;
stack<int>sta;
string wff;
using namespace std;
void solve2() {
	for (int i = wff.size() - 1; i >= 0; i--) {
		if (wff[i] == 'p' ) {
			sta.push(p);
		} else if (wff[i] == 'q') {
			sta.push(q);
		} else if (wff[i] == 'r') {
			sta.push(r);
		} else if (wff[i] == 's') {
			sta.push(s); 
		} else if (wff[i] == 't') {
			sta.push(t);
		} else if (wff[i] == 'N') {
			sta.top() = !sta.top();
		} else if (wff[i] == 'K') {
			tmp = sta.top();
			sta.pop();
			sta.top() = (tmp && sta.top());
		} else if (wff[i] == 'A') {
			tmp = sta.top();
			sta.pop();
			sta.top() = (tmp || sta.top());
		} else if (wff[i] == 'C') {
			tmp = sta.top();
			sta.pop();
			if (tmp == 1 && sta.top() == 0) {
				sta.top() = 0;
			} else {
				sta.top() = 1;
			}
		} else if (wff[i] == 'E') {
			tmp = sta.top();
			sta.pop();
			if (tmp == sta.top()) {
				sta.top() = 1;
			} else {
				sta.top() = 0;
			}
		}
	}
}
bool solve() {
	for (p = 0; p < 2; p++)
	    for (q = 0; q < 2; q++)
	        for (r = 0; r < 2; r++)
	            for (s = 0; s < 2; s++)
	                for (t = 0; t < 2; t++) {
	                	solve2();
	                	if (sta.top() == 0) {
	                		return false;
	                	}
	                	sta.pop();
	                }
	return true;
}
int main() {
	while (cin >> wff && wff[0] != '0') {
		if (solve()) {
			cout << "tautology" << endl;
		} else {
			cout << "not" << endl;
		}
	} 
    return 0;
}

