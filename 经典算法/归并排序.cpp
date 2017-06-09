/*http://www.cnblogs.com/jillzhang/archive/2007/09/16/894936.html*/
# include <stdio.h>
int a[20001], temp[20001];

void Merge(int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
        }
        printf("fff\n");
    }
    while (i <= mid) {
        temp[k++] = a[i++];
    }
    while (j <= right) {
        temp[k++] = a[j++];
    }
    for (int x = left; x <= right; x++) {
        a[x] = temp[x];
    }
}

void MergeSort(int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        MergeSort(left, mid);
        MergeSort(mid + 1, right);
        Merge(left, mid, right);
    }
}

int main() {
	int t, n, i;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		    scanf("%d", &a[i]);
		
		MergeSort(0, n - 1);
		
		for (i = 0; i < n; i++) {
			printf("%d\n", a[i]);
		}
    }
	return 0;
}

