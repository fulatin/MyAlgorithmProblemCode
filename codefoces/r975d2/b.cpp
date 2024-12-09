#include <bits/stdc++.h>
#include <climits>

using namespace std;
typedef long long ll;
ll t, n, q;
vector<int> arr;
unordered_map<ll, ll> mps;
void solve() {
  arr.clear();
  mps.clear();
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    int curr;
    cin >> curr;
    arr.push_back(curr);
  }
  for (ll i = 1; i <= n; ++i) {
    mps[(i - 1ll) * (n - i) + n - 1ll] += 1ll;
    mps[i * (n - i)] += arr[i] - arr[i - 1ll] - 1ll;
  }
  while (q--) {
    ll k;
    cin >> k;
    cout << mps[k] << ' ';
  }
  cout << endl;
}

int main() {
  cin >> t;
  while (t--) {
    solve();
  }
}
