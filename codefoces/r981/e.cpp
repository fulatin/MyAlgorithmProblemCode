#include <bits/stdc++.h>
#include <cstring>

using namespace std;

int t, n;
int ans = 0;
unordered_set<int> g[1000002];
bool vis[1000002];
int perm[1000002];

int dfs(int k) {
  vis[k] = 1;
  for (auto e : g[k]) {
    if (vis[e])
      continue;
    return 1 + dfs(e);
  }
  return 0;
}

void solve() {
  cin >> n;
  ans = 0;
  for (int i = 1; i <= n; ++i)
    g[i].clear();
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= n; ++i) {
    int curr;
    cin >> curr;
    g[curr].insert(i);
    g[i].insert(curr);
  }

  for (int i = 1; i <= n; ++i) {
    if (vis[i])
      continue;
    ans += dfs(i) / 2;
  }

  cout << ans << endl;
}

int main() {
  cin >> t;
  while (t--)
    solve();
  return 0;
}
