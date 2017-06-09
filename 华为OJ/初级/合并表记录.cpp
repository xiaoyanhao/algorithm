#include <iostream>
#include <map>

using namespace std;


int main() {
  int n, index, value;
  map<int, int> record;
  map<int, int>::iterator it;

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> index >> value;

    if (record.count(index) > 0) {
      record[index] += value;
    } else {
      record[index] = value;
    }
  }

  for (it = record.begin(); it != record.end(); it++) {
    cout << it->first << endl << it->second << endl;
  }

  return 0;
}
