
#include <bits/stdc++.h>

using namespace std;
const int MAXNA = 2000000003;
int t, n, x;
// vector<vector<bool>> arr;
// void solve() {
//   cin >> n >> x;
//   int blocks = n / x;
//   arr.resize(blocks + 1);
//   for (int i = 0; i <= blocks; ++i) {
//     arr[i].resize(x);
//     arr[i].clear();
//   }
//   for (int i = 1; i <= n; ++i) {
//     int curr;
//     cin >> curr;
//     int cb = curr / x;
//     int bpos = curr % x;
//     for (int k = cb; k <= blocks; k++) {
//       if (!arr[k][bpos]) {
//         arr[k][bpos] = true;
//         break;
//       }
//     }
//   }
//   for (int i = 0; i <= blocks; ++i) {
//     for (int j = 0; j < x; ++j) {
//       if (!arr[i][j]) {
//         cout << i * x + j << endl;
//         return;
//       }
//     }
//   }
// }
typedef long long ll;
void solve() {
  cin >> n >> x;
  unordered_map<ll, ll> m;
  for (int i = 1; i <= n; ++i) {
    int curr;
    cin >> curr;
    m[curr]++;
  }
  ll ans = -1;
  for (int i = 0; i <= n; ++i) {
    if (m[i] == 0) {
      ans = i;
      break;
    } else {
      m[i + x] += m[i] - 1;
    }
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> t;
  while (t--) {
    solve();
  }
}
