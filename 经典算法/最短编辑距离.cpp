#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int LevenshteinDistance(string a, string b) {
  int aLen = a.length();
  int bLen = b.length();

  vector< vector<int> > dis(aLen, vector<int>(bLen, 0));

  for (int i = 0; i < aLen; i++) {
    dis[i][0] = i;
  }

  for (int j = 0; j < bLen; j++) {
    dis[0][j] = j;
  }

  for (int i = 1; i < aLen; i++) {
    for (int j = 1; j < bLen; j++) {
      if (a[i - 1] == b[j - 1]) {
        dis[i][j] = dis[i - 1][j - 1];
      } else {
        dis[i][j] = min(min(dis[i - 1][j], dis[i][j - 1]), dis[i - 1][j - 1]) + 1;
      }
    }
  }

  return dis[aLen - 1][bLen - 1];
}

int main() {
  string a, b;

  cin >> a >> b;

  cout << stringDistance(a, b) << endl;

  return 0;
}
