#include <bits/stdc++.h>
#define MAXN 200003
using namespace std;
string s;
bool ans;
int t, n, m, k;
void solve() {

  cin >> n >> m >> k;
  s.clear();
  ans = false;
  cin >> s;
  vector<int> dp(n + 2, -1);
  dp[0] = k;
  if (s[0] == 'L') {
    dp[1] = k;
  } else if (s[0] == 'W') {
    dp[1] = k - 1;
  }
  for (int i = 2; i <= n + 1; i++) {
    if (s[i - 1] == 'C') {
      continue;
    }
    for (int j = 1; j <= m; ++j) {
      if (i - j - 1 < -1)
        break;
      if (j == 1 || i - j - 1 == -1 || s[i - j - 1] == 'L')
        dp[i] = max(dp[i], dp[i - j]);
    }
    if (s[i - 1] == 'W') {
      dp[i]--;
    }
  }
  if (dp[n + 1] >= 0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin >> t;
  while (t--)
    solve();
  return 0;
}
