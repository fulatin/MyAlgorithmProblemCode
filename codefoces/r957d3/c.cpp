#include <bits/stdc++.h>

using namespace std;

int n, m, k, t;

void solve() {
  cin >> n >> m >> k;
  vector<int> arr(n);
  for (int i = n; i >= k; --i) {
    arr.push_back(i);
  }
  for (int i = k - 1; i > m; --i) {
    arr.push_back(i);
  }
  for (int i = 1; i <= m; ++i) {
    arr.push_back(i);
  }
  for (int i = n; i < 2 * n; ++i) {
    cout << arr[i] << ' ';
  }
  cout << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin >> t;
  while (t--) {
    solve();
  }
}
