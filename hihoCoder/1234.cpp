#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

#define eps 1e-10
double lines[1001];

void init() {
    double x = 0.5;
    lines[0] = 0.0;
    for (int i = 1; i < 1000 && 0.5 - lines[i - 1] > eps; i++) {
        x /= 2.0;
        lines[i] = x + lines[i - 1];
    }
}

int main() {
    init();

    int t;

    cin >> t;

    while (t--) {
        double k;

        cin >> k;

        for (int i = 0; i < 1000; i++) {
            if (fabs(k - lines[i]) <= eps) {
                cout << -1 << endl;
                break;
            } else if (k < lines[i + 1] && k > lines[i]) {
                cout << 4 * (i + 1) << endl;
                break;
            }
        }

    }

    return 0;
}