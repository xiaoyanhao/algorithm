#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
  string name;
  int candidate, voter;
  map<string, int> candidates;
  map<string, int>::iterator it;

  cin >> candidate;

  for (int i = 0; i < candidate; i++) {
    cin >> name;
    candidates[name] = 0;
  }
  candidates["Invalid"] = 0;

  cin >> voter;

  for (int i = 0; i < voter; i++) {
    cin >> name;
    
    if (candidates.count(name) > 0) {
      candidates[name]++;
    } else {
      candidates["Invalid"]++;
    }
  }

  for (it = candidates.begin(); it != candidates.end(); it++) {
    cout << it->first << " : " << it->second << endl;
  }

  return 0;
}
