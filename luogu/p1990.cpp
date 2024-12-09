#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
LL f[1000002], g[1000002];

int main() {
  f[1] = 1;
  g[2] = 2;
  f[2] = 2;
  int n;
  cin >> n;
  for (int i = 3; i <= n; ++i) {
    f[i] = f[i - 1] + f[i - 2] + g[i - 1];
    f[i] %= 10000;
    g[i] = f[i - 2] * 2LL + g[i - 1];
    g[i] %= 10000;
  }
  cout << f[n] % 10000;
  return 0;
}
