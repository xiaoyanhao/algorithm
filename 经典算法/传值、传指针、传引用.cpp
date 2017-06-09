#include <iostream>
#include <ctime>
using namespace std;

struct Node {
	int num[1000];
};

void testByValue(Node a) { }
void testByReference(Node &a) { }
void testByPointer(Node *a) { }


void mySwap1(int a, int b) {
    cout << &a << " " << &b << endl;
    int temp = a;
    a = b;
    b = temp;
    cout << &a << " " << &b << endl;
}

void mySwap2(int &a, int &b) {
    cout << &a << " " << &b << endl;
    int temp = a;
    a = b;
    b = temp;
    cout << &a << " " << &b << endl;
}

void mySwap3(int *a, int *b) {
    cout << &a << " " << &b << endl;
    cout << a << " " << b << endl;
    int *temp = a;
    a = b;
    b = temp;
    cout << &a << " " << &b << endl;
    cout << a << " " << b << endl;
}

void mySwap4(int *a, int *b) {
    cout << &a << " " << &b << endl;
    cout << a << " " << b << endl;
    int temp = *a;
    *a = *b;
    *b = temp;
    cout << &a << " " << &b << endl;
    cout << a << " " << b << endl;
}


int main() {
    int n = 5, m = 10;
    cout << "before:\tn = " << n << ",\tm = " << m << endl;
    
    mySwap1(n, m);
    cout << "after1:\tn = " << n << ",\tm = " << m << endl;
    
    n = 5, m = 10;
    mySwap2(n, m);
    cout << "after2:\tn = " << n << ",\tm = " << m << endl;
    
    n = 5, m = 10;
    mySwap3(&n, &m);
    cout << "after3:\tn = " << n << ",\tm = " << m << endl;
    
    n = 5, m = 10;
    mySwap4(&n, &m);
    cout << "after4:\tn = " << n << ",\tm = " << m << endl;
    
    cout << endl << endl << endl;
    time_t startTime, endTime;
    Node p;
    p.num[0] = 2222;
    int maxNum = 10000000;
    int i = maxNum;
    
    startTime = clock();
    while (i--) {
        testByValue(p);
    }
    endTime = clock();
    cout << "testByValue: " << (double)(endTime-startTime) << "ms" << endl;
    
    i = maxNum;
    startTime = clock();
    while (i--) {
        testByReference(p);
    }
    endTime = clock();
    cout << "testByReference: " << (double)(endTime-startTime) << "ms" << endl;
    
    i = maxNum;
    startTime = clock();
    while (i--) {
        testByPointer(&p);
    }
    endTime = clock();
    cout << "testByPointer: " << (double)(endTime-startTime) << "ms" << endl;
    
    return 0;
}
