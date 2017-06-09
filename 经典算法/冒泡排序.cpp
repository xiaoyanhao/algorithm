#include <iostream>

using namespace std;

void bubbleSort(int *a, int len) {

    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

void selectionSort(int *a, int len) {

    for (int i = 0; i < len - 1; i++) {
        int iMin = i;
        for (int j = i + 1; j < len; j++) {
            if (a[j] < a[iMin]) {
                iMin = j;
            }
        }
        if (iMin != i) {
            int tmp = a[i];
            a[i] = a[iMin];
            a[iMin] = tmp;
        }
    }
}

void insertSort(int *a, int len) {

    for (int i = 1; i < len; i++) {
        int tmp = a[i], j = i;
        for (; j > 0 && a[j - 1] > tmp; j--) {
            a[j] = a[j - 1];
        }
        a[j] = tmp;
    }
}

int main(int argc, char const *argv[]) {
    int a[10] = {31, 520, 1314, 0, -31, -520, -1314, -1, 2, 100};

    bubbleSort(a, 10);
    selectionSort(a, 10);
    insertSort(a, 10);

    for (int i = 0; i < 10; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;

    return 0;
}