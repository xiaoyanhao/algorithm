#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string getPwdSecurityLevel(string pwd) {
  string level;
  int upperCase = 0;
  int lowerCase = 0;
  int digit = 0;
  int symbol = 0;
  int score = 0;
  int len = pwd.length();

  for (int i = 0; i < len; i++) {
    char c = pwd[i];
    if (isdigit(c)) {
      digit++;
    } else if (isupper(c)) {
      upperCase++;
    } else if (islower(c)) {
      lowerCase++;
    } else if ((c >= 0x21 && c <= 0x2f) ||
      (c >= 0x3a && c <= 0x40) ||
      (c >= 0x5b && c <= 0x60) ||
      (c >= 0x7b && c <= 0x71)) {
      symbol++;
    }
  }

  if (len <= 4) {
    score += 5;
  } else if (len <= 7) {
    score += 10;
  } else {
    score += 25;
  }

  if (upperCase) {
    score += 10;
  }
  if (lowerCase) {
    score += 10;
  }

  if (digit == 1) {
    score += 10;
  } else if (digit > 1) {
    score += 20;
  }

  if (symbol == 1) {
    score += 10;
  } else if (symbol > 1) {
    score += 25;
  }

  if ((upperCase + lowerCase) && digit) {
    score += 2;
    if (symbol) {
      score += 1;
      if (upperCase && lowerCase) {
        score += 2;
      }
    }
  }

  if (score >= 90) {
    level = "VERY_SECURE";
  } else if (score >= 80) {
    level = "SECURE";
  } else if (score >= 70) {
    level = "VERY_STRONG";
  } else if (score >= 60) {
    level = "STRONG";
  } else if (score >= 50) {
    level = "AVERAGE";
  } else if (score >= 25) {
    level = "WEAK";
  } else {
    level = "VERY_WEAK";
  }

  return level;
}

int main() {
  string pwd;

  getline(cin, pwd);

  cout << getPwdSecurityLevel(pwd) << endl;

  return 0;
}
