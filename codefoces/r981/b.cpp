#include <bits/stdc++.h>

using namespace std;

const int MAXN = 503;

int t;
int grid[MAXN][MAXN];
int n;

void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> grid[i][j];
    }
  }
  long long ans = 0;
  for (int j = 1; j <= n; ++j) {
    int mnv = 0;
    for (int k = 0; k <= n - j; ++k) {
      mnv = min(grid[1 + k][j + k], mnv);
    }
    ans -= mnv;
  }
  for (int i = 2; i <= n; ++i) {
    int mnv = 0;
    for (int k = 0; k <= n - i; ++k) {
      mnv = min(mnv, grid[i + k][1 + k]);
    }
    ans -= mnv;
  }
  cout << ans << endl;
}

int main() {
  cin >> t;
  while (t--)
    solve();
  return 0;
}
