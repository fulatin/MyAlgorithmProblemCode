#include <iostream>

using namespace std;

double a, b, c, d;
double f(double x) { return x * (x * (a * x + b) + c) + d; }
double search(double l, double r) {
  while (r - l > 0.00001) {
    double mid = (l + r) / 2;
    if (f(l) * f(mid) <= 0)
      r = mid;
    else
      l = mid;
  }
  return r;
}
int main() {

  cin >> a >> b >> c >> d;
  double last = -100 - 0.23123;
  while (last <= 100 + 1.23123) {
    if (f(last) * f(last + 1.0) <= 0)
      printf("%.2lf ", search(last, last + 1.0));
    last += 1.0;
  }
  return 0;
}
