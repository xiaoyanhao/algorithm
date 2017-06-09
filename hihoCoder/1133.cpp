#include <iostream>
#include <algorithm>

using namespace std;

int a[1000001];

int binarySearch(int left, int right, int k) {
    int i = left, j = right;

    int mid = (left + right) / 2;
    int m = a[mid];

    while (i <= j) {
        while (a[i] < m) {
            i++;
        }

        while (a[j] > m) {
            j--;
        }

        if (i <= j) {
            swap(a[i++], a[j--]);
        }
    }

    if (i - j == 2) {
        mid = i - 1;
        m = a[mid];
    } else if (m == a[j]) {
        mid = j;
    } else {
        mid = i;
    }

    if (k == mid) {
        return m;
    } else if (k < mid && left <= j) {
        return binarySearch(left, j, k);
    } else if (k > mid && i <= right) {
        return binarySearch(i, right, k);
    } else {
        return -1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    cout << binarySearch(1, n, k) << endl;

    return 0;
}
