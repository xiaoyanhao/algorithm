#include <iostream>

using namespace std;

const int MOD = 19999997;
const int SIZE = 2;

struct Matrix {
    long m[SIZE][SIZE];
};

Matrix matrix_mul(Matrix a, Matrix b) {
    Matrix c;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            c.m[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                c.m[i][j] += (a.m[i][k] * b.m[k][j]) % MOD;
            }
            c.m[i][j] %= MOD;
        }
    }

    return c;
}

long matrix_pow(int n) {
    Matrix base, ans;

    base.m[0][0] = 0;
    base.m[0][1] = base.m[1][0] = base.m[1][1] = 1;

    ans.m[0][0] = ans.m[1][1] = 1; // ans初始化为单位矩阵
    ans.m[0][1] = ans.m[1][0] = 0;

    while (n != 0) {
        if (n & 1) {
            ans = matrix_mul(ans, base);
        }
        base = matrix_mul(base, base);
        n >>= 1;
    }

    return ans.m[1][1] % MOD;
}

int main() {
    int n;

    cin >> n;

    cout << matrix_pow(n) << endl;

    return 0;
}