#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N = (int)10e5;
ll n, x;
ll arr[N + 3];
ll accum[N + 2];

int main() {
  ios::sync_with_stdio(false);

  cin >> n >> x;
  for (ll i = 1; i <= n; ++i) {
    cin >> arr[i];
  }

  for (ll i = 1; i <= n; ++i) {
    accum[i] = arr[i - 1] + arr[i];
  }

  ll cnt = 0;
  for (ll i = 1; i <= n; ++i) {

    if (accum[i] > x) {
      ll more = accum[i] - x;
      cnt += more;
      accum[i] -= more;
      accum[i + 1] -= more;
    }
  }
  cout << cnt;
  return 0;
}
