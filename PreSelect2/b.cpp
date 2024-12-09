
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
void solve() {
  LL a;
  cin >> a;
  while (a > 1ll) {
    if (a % 2ll == 0)
      a /= 2;
    else
      break;
  }
  if (a > 1)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
}
