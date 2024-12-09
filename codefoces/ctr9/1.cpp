#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cout << i + i - 1 << ' ';
  }
  cout << endl;
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--)
    solve();
  return 0;
}
