# include <iostream>

using namespace std;

int main() {
    int N;

    cin >> N;

    while (N--) {
        string ori, par;
        int next[10001] = {}, count = 0;
        next[0] = -1;

        cin >> par >> ori;

        int par_len = par.size();
        for (int i = 0, j = -1; i < par_len; ) {
            if (j == -1 || par[i] == par[j]) {
                next[++i] = ++j;
            } else {
                j = next[j];
            }
        }

        int ori_len = ori.size();
        for (int i = 0, j = 0; i < ori_len; ) {
            if (j == -1 || ori[i] == par[j]) {
                i++;
                j++;
            } else {
                j = next[j];
            }
            if (j == par_len) {
                count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}
