#include <iostream>
#include <set>

using namespace std;

int main() {
  int n, m, v;
  set<int> myset;
  set<int>::iterator it;

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> v;
    myset.insert(v);
  }

  cin >> m;

  for (int i = 0; i < m; i++) {
    cin >> v;
    myset.insert(v);
  }

  for (it = myset.begin(); it != myset.end(); it++) {
    cout << *it;
  }
  cout << endl;

  return 0;
}
