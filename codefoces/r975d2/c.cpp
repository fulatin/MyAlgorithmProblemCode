#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN = 2 * 100000 + 2;
int n;
ll k;
ll arr[MAXN];
int t;

void solve() {
  cin >> n >> k;
  ll tot = 0;
  ll mx = -1;
  for (int i = 1; i <= n; ++i) {
    ll curr;
    cin >> curr;
    tot += curr;
    mx = max(curr, mx);
  }
  int ans = 1;
  for (int i = n; i >= 1; i--) {
    ll j = max((tot + i - 1) / i, mx);
    if (i * j <= tot + k) {
      ans = i;
      break;
    }
  }
  cout << ans << endl;
}

int main() {
  cin >> t;
  while (t--)
    solve();
}
