#include <iostream>
#include <cstdio>
using namespace std;

int a[1000];

void quickSort(int left, int right) {
    int i = left, j = right, mid = a[(left + right) / 2];
    while (i <= j) {
        while (a[i] < mid) {
            i++;
        }
        while (a[j] > mid) {
            j--;
        }
        if (i <= j) {
            swap(a[i++], a[j--]);
        }
    }
    if (i < right) {
        quickSort(i, right);
    }
    if (left < j) {
        quickSort(left, j);
    }
} 

int main() {
	int t, n, i;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		    scanf("%d", &a[i]);
		
		quickSort(0, n - 1);
		
		for (i = 0; i < n; i++) {
			printf("%d\n", a[i]);
		}
    }
	return 0;
}
