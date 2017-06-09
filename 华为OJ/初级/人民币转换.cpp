#include <iostream>
#include <string>

using namespace std;

string rmbUnits[] = {
  "零", "壹", "贰", "叁", "肆",
  "伍", "陆", "柒", "捌", "玖", "拾"
};

string toRMBInteger(long n) {
  string s = "";
  long q, r;

  if (n >= 100000000) {
    q = n / 100000000;
    r = n % 100000000;
    s = toRMBInteger(q) + "亿";
    if (r) {
      s += (r < 10000000 ? "零" : "") + toRMBInteger(r);
    }
  } else if (n >= 10000) {
    q = n / 10000;
    r = n % 10000;
    s = toRMBInteger(q) + "万";
    if (r) {
      s += (r < 1000 ? "零" : "") + toRMBInteger(r);
    }
  } else if (n >= 1000) {
    q = n / 1000;
    r = n % 1000;
    s = toRMBInteger(q) + "仟";
    if (r) {
      s += (r < 100 ? "零" : "") + toRMBInteger(r);
    }
  } else if (n >= 100) {
    q = n / 100;
    r = n % 100;
    s = toRMBInteger(q) + "佰";
    if (r) {
      s += (r < 10 ? "零" : "") + toRMBInteger(r);
    }
  } else if (n >= 10) {
    q = n / 10;
    r = n % 10;
    s = q > 1 ? toRMBInteger(q) + "拾" : "拾";
    s += r != 0 ? toRMBInteger(r) : "";
  } else {
    s = rmbUnits[n];
  }

  return s;
}

string toRMBFrgction(double n) {
  int m = int(n * 100.0 + 0.001);
  int jiao = m / 10;
  int fen = m % 10;

  string fraction = "";

  if (jiao == 0 && fen == 0) {
    fraction = "整";
    return fraction;
  }

  if (jiao != 0) {
    fraction += rmbUnits[jiao] + "角";
  }
  if (fen != 0) {
    fraction += rmbUnits[fen] + "分";
  }

  return fraction;
}

string toRMB(double n) {
  long i = long(n);
  double f = n - i;
  string integer = (i > 0) || (i == 0 && f == 0) ? toRMBInteger(i) + "元" : "";
  string fraction = toRMBFrgction(f);
  string rmb = "人民币" + integer + fraction;

  return rmb;
}

int main() {
  double n;

  cin >> n;

  cout << toRMB(n) << endl;

  return 0;
}
