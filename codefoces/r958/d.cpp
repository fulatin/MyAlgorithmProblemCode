#include <bits/stdc++.h>
const int MAXN = 300002;
using namespace std;

set<int> g[MAXN];
long long dp[MAXN][24];
long long att[MAXN];

int n;
void dfs(int x, int f) {
  if (x > n)
    return;
  for (int i = 1; i <= 23; ++i)
    dp[x][i] = i * att[x];

  for (int y : g[x]) {
    if (y == x || y == f) {
      continue;
    }

    dfs(y, x);
    for (int i = 1; i <= 23; ++i) {
      long long mn = 0x7fffffffffffffff;
      for (int j = 1; j <= 23; ++j) {
        if (j == i)
          continue;
        mn = min(mn, dp[y][j]);
      }
      dp[x][i] += mn;
    }
  }
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> att[i];
  }
  for (int i = 1; i <= n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    g[x].insert(y);
    g[y].insert(x);
  }
  dfs(1, 0);
  long long ans = 0xfffffffffffffff;
  for (int i = 1; i <= 23; ++i) {
    ans = min(ans, dp[1][i]);
  }
  cout << ans << endl;
  for (int i = 1; i <= n; ++i) {
    g[i].clear();
  }
}
int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
