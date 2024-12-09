#include <bits/stdc++.h>
#include <cstring>
using namespace std;

const int MAXN = 500000;
int t, mindp;

set<int> g[MAXN];
bool vis[MAXN + 3];
int dph[MAXN + 2];
void dfs(int p, int dp) {

  dph[p] = dp;
  vis[p] = true;
  for (auto e : g[p]) {
    if (vis[e])
      continue;
    dfs(e, dp + 1);
  }
  if (g[p].size() == 1) {
    mindp = min(mindp, mindp);
  }
}
void solve() {
  int n;
  cin >> n;
  memset(vis, false, sizeof(vis));
  for (int i = 1; i <= n; ++i) {
    g[i].clear();
  }
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].insert(v);
    g[v].insert(u);
  }
  dfs(1, 1);
}
int main() {
  cin >> t;
  while (t--) {
    solve();
  }
}
