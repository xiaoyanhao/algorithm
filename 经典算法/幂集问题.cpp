/*所谓幂集（Power Set）， 就是原集合中所有的子集（包括全集和空集）构成的集族。

我们这个题的任务就是将一个集合的幂集解出来。

我们假设原始集合是一个由数字组成的集合，并且是从1~N的连续整数。

输入一个N，则这个集合的内容是{1, 2, 3, ⋯⋯, N}。

求解幂集之后按照一定的顺序输出出来，这个顺序是这样的：

对于一个集合，我们将集合内的元素按照从大到小排序。

对于两个集合之间，我们按照从小到大排序，如何比较两个集合之间的大小关系呢？

先从左往右比较集合的元素，哪个集合先遇到大于另一个集合的数字，则说明比它大，如果注意空比任何数字都要小，比如：

{2} < {2, 1}

{1} < {2}

{3, 1} < {3, 2}
*/
#include <iostream>
#include <cstring>
using namespace std;
int a[20], b[20], n;
int S[10000][20], tot;
void getPowerSet(int i) {
    if (i >= n) {
        if (b[0]) {
            for (int j = 0; b[j] != 0; j++) {
                S[tot][j] = b[j];
            }
            tot++;
        }
    } else {
        int c = a[i];
        int j = 0;
        while (b[j]) {
            j++;
        }
        b[j] = c;
        getPowerSet(i + 1);
        b[j] = 0;
        getPowerSet(i + 1);
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            a[i] = n - i;
        }
        tot = 0;
        getPowerSet(0);
        cout << "{}" << endl;
        if (S[tot - 1][0]) {
            for (int i = tot - 1; i >= 0; i--) {
                cout << "{" << S[i][0];
                for (int j = 1; S[i][j] != 0; j++) {
                    cout << "," << S[i][j];
                }
                cout << "}" << endl;
            }   
        }
    }
    return 0;
}
