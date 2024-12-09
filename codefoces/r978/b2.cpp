#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
int t;
void solve() {
  int n, x;
  cin >> n >> x;
  LL mx = -1;
  LL sum = 0;
  for (int i = 1; i <= n; ++i) {
    LL curr;
    cin >> curr;
    sum += curr;
    mx = max(mx, curr);
  }
  LL ans = mx;
  ans = max(ans, (sum + x - 1) / x);
  cout << ans << endl;
}
int main() {
  cin >> t;
  while (t--)
    solve();
  return 0;
}
