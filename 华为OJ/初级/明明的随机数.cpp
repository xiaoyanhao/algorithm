#include <iostream>
#include <set>

using namespace std;

int main() {
  int n, m;

  cin >> n;

  set<int> s;
  set<int>::iterator it;

  for (int i = 0; i < n; i++) {
    cin >> m;
    s.insert(m);
  }

  for (it = s.begin(); it != s.end(); it++) {
    cout << *it << endl;
  }

  return 0;
}
