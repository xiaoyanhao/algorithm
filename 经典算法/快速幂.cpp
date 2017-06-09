# include <stdio.h>

// 常规求幂
int pow1(int a, int b) {
    int r = 1;
    while (b--) {
        r *= a;
    }
    return r;
}

// 二分求幂
int pow2(int a, int b) {
    int r = 1, base = a;
    while (b != 0) {
        if (b % 2) {
            r *= base;
        }
        base *= base;
        b /= 2;
    }
    return r;
}

// 快速求幂（位操作）
int pow3(int a, int b) {
    int r = 1, base = a;
    while (b != 0) {
        if (b & 1) {
            r *= base;
        }
        base *= base;
        b >>= 1;
    }
    return r;
}
