#include <bits/stdc++.h>

using namespace std;

int t;

void solve() {
  int n, x, y;
  cin >> n >> x >> y;
  int m = min(x, y);
  cout << (n + m - 1) / m << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin >> t;
  while (t--) {
    solve();
  }
}
