#include <iostream>
#include <string>
#include <map>
#include <cctype>

using namespace std;

string encrypt(string key, string data) {
  string alphabet = "", encrypt = "";
  map<char, char> mapping;
  int len = key.length();

  for (int i = 0; i < len; i++) {
    key[i] = tolower(key[i]);
  }

  for (int i = 0; i < 26; i++) {
    alphabet += 'a' + i;
  }

  key += alphabet;
  len = key.length();

  for (int i = 0; i < len; i++) {
    char letter = key[i];
    int pos = key.find_first_of(letter, 0);

    if (pos == i) {
      encrypt += letter;
    }
  }

  for (int i = 0; i < 26; i++) {
    mapping[alphabet[i]] = encrypt[i];
  }

  encrypt = "";
  len = data.length();

  for (int i = 0; i < len; i++) {
    char c = data[i];

    if (islower(c)) {
      c = mapping[c];
    } else if (isupper(c)) {
      c = mapping[tolower(c)] - ('a' - 'A');
    }

    encrypt += c;
  }

  return encrypt;
}

int main() {
  string key, data;

  getline(cin, key);
  getline(cin, data);

  cout << encrypt(key, data) << endl;

  return 0;
}
