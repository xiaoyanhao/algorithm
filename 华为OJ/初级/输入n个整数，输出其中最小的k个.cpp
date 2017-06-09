#include <iostream>
#include <algorithm>

using namespace std;

void maxHeapify(int a[], int i, int n) {
  int dad = i;
  int son = 2 * dad + 1;

  while (son < n) {
    if (son + 1 < n && a[son] < a[son + 1]) {
      son++;
    }

    if (a[dad] > a[son]) {
      return;
    } else {
      swap(a[dad], a[son]);
      dad = son;
      son = 2 * dad + 1;
    }
  }
}

int main() {
  int n, k;

  cin >> n >> k;

  int *a = new int[n];

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int *heap = new int[k];

  for (int i = 0; i < k; i++) {
    heap[i] = a[i];
  }

  for (int i = k / 2 - 1; i >= 0; i--) {
    maxHeapify(heap, i, k);
  }

  for (int i = k; i < n; i++) {
    if (heap[0] > a[i]) {
      heap[0] = a[i];
      maxHeapify(heap, 0, k);
    }
  }

  // sort(heap, heap + k);
  for (int i = k - 1; i > 0; i--) {
    swap(heap[0], heap[i]);
    maxHeapify(heap, 0, i);
  }

  cout << heap[0];
  for (int i = 1; i < k; i++) {
    cout << ' ' << heap[i];
  }
  cout << endl;

  delete[] a;
  delete[] heap;

  return 0;
}
