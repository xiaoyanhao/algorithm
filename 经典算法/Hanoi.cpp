#include <iostream>
using namespace std;

//移动的最小次数为 2^n - 1 

void move(int n, int x, int y) {
    cout << "move disk " << n << " from peg " << x << " to peg " << y << endl;
}

void hanoi(int n, int a, int b, int c) {
    if (n == 1) {
        move(1, a, c);
    } else {
        hanoi(n - 1, a, c, b);
        move(n, a, c);
        hanoi(n - 1, b, a, c);
    }
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        hanoi(n, 1, 2, 3);
    }
    return 0;
}

