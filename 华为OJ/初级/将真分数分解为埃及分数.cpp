#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

string intToString(int n) {
  ostringstream oss;
  oss << n;
  return oss.str();
}

string getReciprocal(int n) {
  return "1/" + intToString(n);
}

int main() {
  string fraction;
  string exp = "";

  cin >> fraction;

  int slashPos = fraction.find('/');
  int numerator = atoi(fraction.substr(0, slashPos).c_str());
  int denominator = atoi(fraction.substr(slashPos + 1).c_str());

  while (numerator != 1) {
    if (denominator % (numerator - 1) == 0) {
      exp += getReciprocal(denominator / (numerator - 1)) + "+";
      numerator = 1;
    } else {
      int newDenominator = denominator / numerator + 1;
      numerator = numerator * newDenominator - denominator;
      denominator = denominator * newDenominator;
      exp += getReciprocal(newDenominator) + "+";

      if (denominator % numerator == 0) {
        denominator = denominator / numerator;
        numerator = 1;
      }
    }
  }

  exp += getReciprocal(denominator);

  cout << exp << endl;

  return 0;
}
