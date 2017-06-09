#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<string> split(string s) {
  vector<string> words;
  istringstream iss(s);
  string word;

  while (!iss.eof()) {
    getline(iss, word, ' ');
    words.push_back(word);
  }

  return words;
}

int main() {
  string s;
  getline(cin, s);
  vector<string> words = split(s);

  int size = words.size();
  vector< vector<string> > path(size, vector<string>(size, ""));
  vector< vector<int> > dis(size, vector<int>(size, -1));
  vector<string>::iterator it;

  for (int i = 0; i < size; i++) {
    string suffix = words[i].substr(1);
    for (int j = 0; j < size; j++) {
      string prefix = words[j].substr(0, words[j].size() - 1);
      if (suffix == prefix) {
        dis[i][j] = 1;
        path[i][j] = words[j].substr(words[j].size() - 1);
      }
    }
    dis[i][i] = 0;
  }

  // floyd
  for (int k = 0; k < size; k++) {
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        int ik = dis[i][k];
        int kj = dis[k][j];
        // 防止循环回路
        if (ik != -1 && kj != -1 && dis[i][j] < ik + kj && ik + kj < size) {
          dis[i][j] = ik + kj;
          path[i][j] = path[i][k] + path[k][j];
        }
      }
    }
  }

  int maxDis = 0;
  int beginIndex = 0;
  int endIndex = 0;

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (dis[i][j] > maxDis) {
        maxDis = dis[i][j];
        beginIndex = i;
        endIndex = j;
      }
    }
  }

  cout << words[beginIndex] + path[beginIndex][endIndex] << endl;

  return 0;
}
