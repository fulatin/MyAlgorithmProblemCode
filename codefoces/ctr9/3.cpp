#include <bits/stdc++.h>

using namespace std;

void solve() {
  int x;
  long long m;
  cin >> x >> m;
  int cnt = 0;
  for (int i = 1; i < 2 * x && i <= m; ++i) {
    if ((x ^ i) == 0)
      continue;
    if (x % (x ^ i) == 0 || i % (x ^ i) == 0)
      cnt++;
  }
  cout << cnt << endl;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--)
    solve();
  return 0;
}
