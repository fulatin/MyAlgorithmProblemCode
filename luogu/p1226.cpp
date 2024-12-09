#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long LL;
LL a, b, p;
int main() {
  cin >> a >> b >> p;
  LL cpa = a;
  LL cpb = b;
  LL ans = 1;
  while (cpb > 0) {
    if (cpb & 1)
      ans = (ans * cpa) % p;
    cpa = (cpa * cpa) % p;
    cpb /= 2;
  }
  cout << a << '^' << b << " mod " << p << '=' << ans;
  return 0;
}
