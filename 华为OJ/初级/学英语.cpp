#include <iostream>
#include <string>

using namespace std;

string words[] = {
  "zero", "one", "two", "three", "four", "five",
  "six", "seven", "eight", "nine", "ten",
  "eleven", "twelve", "thirteen", "fourteen", "fifteen",
  "sixteen", "seventeen", "eighteen", "nineteen", "twenty",
  "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
};

string ERROR = "error";
string AND = " and ";
string HUNDRED = "hundred";
string THOUSAND = "thousand";
string MILLION = "million";
string BILLION = "billion";

string parse(long n) {
  if (n <= 0) {
    return ERROR;
  } else if (n < 20) {
    return words[n];
  } else if (n < 100) {
    if (n % 10 == 0) {
      return words[20 + (n - 20) / 10];
    } else {
      return parse(n - n % 10) + " " + parse(n % 10);
    }
  } else if (n < 1000) {
    if (n % 100 == 0) {
      return parse(n / 100) + " " + HUNDRED;
    } else {
      return parse(n / 100) + " " + HUNDRED + AND + parse(n % 100);
    }
  } else if (n < 1000000) {
    if (n % 1000 == 0) {
      return parse(n / 1000) + " " + THOUSAND;
    } else {
      return parse(n / 1000) + " " + THOUSAND + " " + parse(n % 1000);
    }
  } else if (n < 1000000000) {
    if (n % 1000000 == 0) {
      return parse(n / 1000000) + " " + MILLION;
    } else {
      return parse(n / 1000000) + " " + MILLION + " " + parse(n % 1000000);
    }
  } else if (n < 10000000000) {
    if (n % 1000000000 == 0) {
      return parse(n / 1000000000) + " " + BILLION;
    } else {
      return parse(n / 1000000000) + " " + BILLION + " " + parse(n % 1000000000);
    }
  } else {
    return ERROR;
  }
}

int main() {
  long n;

  cin >> n;

  cout << parse(n) << endl;

  return 0;
}
