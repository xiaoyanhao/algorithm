#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(const string &s, char delim) {
  vector<string> substr;
  istringstream iss(s);
  string item;

  while (!iss.eof()) {
    getline(iss, item, delim);
    substr.push_back(item);
  }

  return substr;
}

int ipStringToInt(string ip) {
  vector<string> ips = split(ip, '.');
  vector<string>::iterator it;
  int ipInt = 0;

  for (it = ips.begin(); it != ips.end(); it++) {
    int n = atoi((*it).c_str());
    ipInt <<= 8;
    ipInt += n;
  }

  return ipInt;
}

bool isValidIp(string ip) {
  vector<string> ips = split(ip, '.');
  vector<string>::iterator it;

  if (ips.size() != 4) {
    return false;
  }

  for (it = ips.begin(); it != ips.end(); it++) {
    int n = atoi((*it).c_str());
    if (n < 0 || n > 255) {
      return false;
    }
  }

  return true;
}

int checkNetSegment(string mask, string ip1, string ip2) {
  if (!isValidIp(mask) || !isValidIp(ip1) || !isValidIp(ip2)) {
    return 1;
  }

  int maskInt = ipStringToInt(mask);
  int ip1Int = ipStringToInt(ip1);
  int ip2Int = ipStringToInt(ip2);

  if ((ip1Int & maskInt) == (ip2Int & maskInt)) {
    return 0;
  } else {
    return 2;
  }
}

int main() {
  string mask, ip1, ip2;

  getline(cin, mask);
  getline(cin, ip1);
  getline(cin, ip2);

  cout << checkNetSegment(mask, ip1, ip2) << endl;

  return 0;
}
