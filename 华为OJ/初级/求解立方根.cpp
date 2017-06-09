/**
 * 利用牛顿迭代法求立方根
 * 利用牛顿迭代法求方程F(x)=0的解的公式为x[n+1] = x[n] - F(x[n]) / F'(x[n])。其中x[n]为第n次利用此公式求得值。
 * 若已知a，求x使得x^3 = a，则设函数F(x) = x^3 - a。
 * 根据牛顿迭代法第n+1次求方程F(x) = 0 的解为x[n+1]，且
 * x[n+1] = x[n] - (x^3[n] - a) / (3x^2[n]) = (2x[n] - a / x^2[n]) / 3。
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#define E 0.000001

using namespace std;

double getCubeRoot(double input) {
  double x0;
  double x1 = input;

  do {
    x0 = x1;
    x1 = (2 * x0 + input / (x0 * x0)) / 3;
  } while (fabs(x1 - x0) > E);

  return x1;
}

int main() {
  double n;

  cin >> n;

  cout << fixed << setprecision(1) << getCubeRoot(n) << endl;

  return 0;
}
