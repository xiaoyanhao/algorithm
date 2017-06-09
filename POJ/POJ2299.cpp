# include <iostream>
# include <cstring>
using namespace std;
int a[500005], b[500005];

long long merge(int low, int mid, int high) {
    int i = low, j = mid + 1, k = low;
    long long count = 0;
    while (i <= mid && j <= high) {
        if (a[i] <= a[j]) {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
            count += j - k;
        }
    }
    while (i <= mid) {
        b[k++] = a[i++];
    }
    while (j <= high) {
        b[k++] = a[j++]; 
    }
    for (i = low; i <= high; i++) {
        a[i] = b[i];
    }
    return count;
}

long long mergeSort(int a, int b) {
    if (a < b) {
        int mid = (a + b) / 2;
        long long count = 0;
        count += mergeSort(a, mid);
        count += mergeSort(mid + 1, b);
        count += merge(a, mid, b);
        return count;
    }
    return 0; 
}

int main() {
    int n, i, j, k;
    while (cin >> n && n) {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << mergeSort(0, n - 1) << endl;
    }
    return 0;
} 
