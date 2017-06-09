#include <iostream>
#include <thread>
#include <vector>

using namespace std;

char flag = 'A';
string s = "";

void ThreadFun(int n, int index) {
  for (int i = 0; i < n; i++) {
    char c = 'A' + index;
    while (flag != c);
    s += c;
    flag = 'A' + (index + 1) % 4;
  }
}

int main() {
  int n;

  cin >> n;

  vector<thread> threads;

  for (int i = 0; i < 4; i++) {
    threads.push_back(thread(ThreadFun, n, i));
  }

  for (int i = 0; i < 4; i++) {
    threads[i].join();
  }

  cout << s << endl;

  return 0;
}

// #include <iostream>

// using namespace std;

// int main() {
//   int n;

//   cin >> n;

//   for (int i = 0; i < n; i++) {
//     cout << "ABCD";
//   }

//   cout << endl;
//   return 0;
// }