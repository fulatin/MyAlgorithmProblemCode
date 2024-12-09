
#include <bits/stdc++.h>
#include <cstring>

using namespace std;
const int MAXN = 65539;
set<int> g[MAXN];
int res[MAXN];
int in[MAXN];
int incp[MAXN];
int dfs(int i) {
  if (res[i] != -1)
    return res[i];
  int ans = 0;
  for (auto e : g[i]) {
    incp[e]--;
    if (incp[e] <= 0)
      ans += dfs(e) + 1;
  }
  return res[i] = ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(res, -1, sizeof(res));
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int num;
    cin >> num;
    while (num != 0) {
      g[num].insert(i);
      in[i]++;
      cin >> num;
    }
  }
  for (int i = 1; i <= n; ++i) {
    memcpy(incp, in, sizeof(in));
    if (res[i] != -1)
      cout << res[i] << endl;
    else
      cout << dfs(i) << endl;
  }
  return 0;
}
