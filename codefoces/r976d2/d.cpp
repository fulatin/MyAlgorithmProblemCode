
#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

const int MAXN = 2 * 100000;
int t, n, m;
unordered_set<int> g[MAXN];

bool vis[MAXN];
int ans;

void dfs(int p) {
  if (vis[p])
    return;
  vis[p] = true;
  for (int e : g[p]) {
    if (vis[e])
      continue;
    dfs(e);
  }
}

void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    g[i].clear();
  }
  ans = 0;
  memset(vis, false, (n + 1) * sizeof(bool));
  while (m--) {
    int a, d, k;
    cin >> a >> d >> k;
    for (int i = 1; i <= k; ++i) {
      if (a + (i - 1) * d > n || a + i * d > n)
        break;
      g[a + (i - 1) * d].insert(a + i * d);
      g[a + i * d].insert(a + (i - 1) * d);
    }
  }

  for (int i = 1; i <= n; ++i) {
    if (vis[i])
      continue;
    dfs(i);
    ans++;
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
