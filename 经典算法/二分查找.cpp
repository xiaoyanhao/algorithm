#include <iostream>
using namespace std;

int binarySearch(int a[], int left, int right, const int &x) {
    int mid, i = left, j = right;
    while (i <= j) {
        mid = i + (j - i + 1) / 2;
        if (a[mid] == x) {
            return mid;
        } else if (a[mid] > x) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int binarySearch(int a[], int left, int right, const int &x) {
    int mid, i = left, j = right;
    while (i < j) {
        mid = i + (j - i + 1) / 2;
        if (a[mid] >= x) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    if (a[left] == x) {
        return right;
    }
    return -1;
}

int binarySearch(int a[], int left, int right, const int &x) {
    int mid, i = left, j = right;
    while (i < j) {
        mid = i + (j - i + 1) / 2;
        if (a[mid] <= x) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }
    if (a[right] == x) {
        return left;
    }
    return -1;
}

int main() {
    
    return 0;
} 
