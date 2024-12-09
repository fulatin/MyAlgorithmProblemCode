#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e5 + 4;
double a[MAXN], b[MAXN], p;
int n;

bool check(double x) {
  double cpp = p;
  for (int i = 1; i <= n; ++i) {
    double usedp = a[i] - b[i] / x;
    if (usedp > 0) {
      // printf("for %d we give %lf\n", i, usedp);
      cpp -= usedp;
    }
  }
  // printf("%.17lf %.17lf\n", x, cpp);
  return cpp >= 0;
}

int main() {
  double suma = 0;
  double sumb = 0;
  cin >> n >> p;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    suma += a[i];
    cin >> b[i];
    sumb += b[i];
  }
  if (suma <= p) {
    cout << -1;
    return 0;
  }
  double l = 0, r = sumb / (suma - p);

  while (r - l > 1e-5) {
    double mid = (l + r) / 2;
    if (check(mid))
      l = mid;
    else
      r = mid;
  }
  cout << l;
  return 0;
}
