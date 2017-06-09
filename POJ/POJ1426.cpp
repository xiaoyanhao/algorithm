# include <iostream>
# include <cstring>
# include <queue>
using namespace std;
int n;
long long sum;

void BFS() {
    queue<long long> Q;
    Q.push(1);
    while (!Q.empty()) {
        sum = Q.front();
        Q.pop();
        if (sum % n == 0) {
            cout << sum << endl;
            return;
        }
        Q.push(sum * 10);
        Q.push(sum * 10 + 1);
    }
}

int main() {
    while (cin >> n && n) {
        BFS();
    }
    return 0;
}

