#include <iostream>
#include <set>

#include <utility>
#include <vector>

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<set<int>> g(n + 1);
  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    g[v].insert(u);
    g[u].insert(v);
  }
  vector<tuple<int, int, int>> ans;
  for (int i = 1; i <= n; ++i) {
    while (g[i].size() >= 2) {
      int u = *g[i].begin();
      g[i].erase(g[i].begin());
      int v = *g[i].begin();
      g[i].erase(g[i].begin());
      g[v].erase(i);
      g[u].erase(i);
      ans.emplace_back(i, u, v);

      if (g[u].contains(v)) {
        g[u].erase(v);
        g[v].erase(u);
      } else {
        g[u].insert(v);
        g[v].insert(u);
      }
    }
  }

  vector<int> dot;
  vector<pair<int, int>> p;
  for (int i = 1; i <= n; ++i) {
    if (g[i].empty()) {
      dot.push_back(i);
    } else {
      if (*g[i].begin() > i) {
        p.emplace_back(i, *g[i].begin());
      }
    }
  }
  if (not p.empty()) {
    auto [x, y] = p.back();
    p.pop_back();
    for (auto u : dot) {
      ans.emplace_back(x, y, u);
      tie(x, y) = pair(x, u);
    }

    for (auto [u, v] : p) {
      ans.emplace_back(u, v, y);
    }
  }
  cout << ans.size() << '\n';
  for (auto e : ans) {
    auto [x, y, z] = e;
    printf("%d %d %d \n", x, y, z);
  }
  return;
}

int main() {
  int T;
  cin >> T;
  while (T--)
    solve();
}
