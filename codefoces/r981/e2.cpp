#include <bits/stdc++.h>
#include <cstring>

using namespace std;

const int MAXN = 1000002;
int n;
int arr[MAXN];
bool vis[MAXN];
void solve() {
  memset(vis, 0, sizeof(vis));
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (vis[i])
      continue;
    int len = -1;
    int now = i;
    while (!vis[now]) {
      vis[now] = 1;
      now = arr[now];
      len++;
    }
    ans += len / 2;
  }
  cout << ans << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}
