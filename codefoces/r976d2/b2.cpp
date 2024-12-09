
#include <bits/stdc++.h>
#include <cmath>
using namespace std;
typedef long long ll;
int t;

void solve() {
  ll k;
  cin >> k;
  ll x = floorl((-1.0 + sqrtl(1 + 4 * k)) / 2.0);
  ll now1 = x * (x + 1);
  ll nowpos = x * (x + 2);
  if (k != now1)
    nowpos += k - now1 + 1;
  cout << nowpos << endl;
}

int main() {
  cin >> t;
  while (t--) {
    solve();
  }
}
