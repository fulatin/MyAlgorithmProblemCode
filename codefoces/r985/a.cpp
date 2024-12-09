#include <bits/stdc++.h>

typedef long long LL;

using namespace std;

void solve() {
  int l, r, k;
  cin >> l >> r >> k;
  int ans = r / k - l + 1;
  if (ans < 0)
    cout << 0 << endl;
  else
    cout << ans << endl;
}

int main() {
  int T;
  cin >> T;
  while (T--)
    solve();
}
