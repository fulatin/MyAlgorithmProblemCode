#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int mx = -1;
  int mn = 1000000000;
  for (int i = 1; i <= n; ++i) {
    int curr;
    cin >> curr;
    mx = max(mx, curr);
    mn = min(mn, curr);
  }
  cout << (n - 1) * (mx - mn) << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
}
