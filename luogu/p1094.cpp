#include <bits/stdc++.h>
#include <functional>

using namespace std;

int w, n;

bool vis[100000];
int main() {
  cin >> w >> n;
  vector<int> v;
  for (int i = 0; i < n; ++i) {
    int curr;
    cin >> curr;
    v.push_back(curr);
  }
  int ans = 0;
  sort(v.begin(), v.end(), greater<>());
  for (int i = 0; i <= n; ++i) {
    if (vis[i])
      continue;
    bool has = false;
    for (int j = n - 1; j > i; --j) {
      if (vis[j])
        continue;
      if (v[j] + v[i] <= w) {
        ans++;
        vis[i] = 1;
        vis[j] = 1;
        has = true;
        break;
      }
    }
    if (!has) {
      ans++;
      vis[i] = 1;
    }
  }
  cout << ans;
}
