#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int matrix[21][21] = {}, count = 1;
    int i, j, n;
    
    cin >> n;
    
    for (i = 1; 2 * i <= n + 1; i++) {
        for (j = i; j <= n + 1 - i; j++) {
            matrix[j][n + 1 - i] = count++;
        }
        for (j = n - i; j >= i; j--) {
            matrix[n + 1 - i][j] = count++;
        }
        for (j = n - i; j >= i; j--) {
            matrix[j][i] = count++;
        }
        for (j = i + 1; j <= n - i; j++) {
            matrix[i][j] = count++;
        }
    }
    
    if (2 * i == n + 1) {
        matrix[i][i] = count;
    }
    
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cout << left << setw(3) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}