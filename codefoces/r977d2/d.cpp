#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
LL t, n, m;
const LL MAXV = 1000000000000000000;
void solve() {
  cin >> n >> m;
  vector<LL> sum(m + 2);

  vector<LL> mxpre(m + 2, -MAXV);
  vector<LL> mxsuf(m + 2, -MAXV);

  vector<vector<LL>> l(n + 1, vector<LL>(m + 1, -MAXV));
  vector<vector<LL>> r(n + 1, vector<LL>(m + 1, -MAXV));

  for (LL i = 1; i <= n; ++i) {
    for (LL j = 1; j <= m; ++j) {
      LL curr;
      cin >> curr;
      sum[j] = sum[j - 1] + curr;
    }

    for (LL j = 1; j <= m; ++j) {
      mxpre[j] = max(mxpre[j - 1] + sum[j] - sum[j - 1], sum[j] - sum[j - 1]);
    }
    for (LL j = m; j >= 1; j--) {
      mxsuf[j] = max(mxsuf[j + 1] + sum[j] - sum[j - 1], sum[j] - sum[j - 1]);
    }

    if (i == 1) {
      for (LL j = 1; j <= m; ++j) {
        l[i][j] = mxsuf[j];
        r[i][j] = mxpre[j];
      }
    } else {
      // ll 为从i-1 天的l 转移到 i 的 l
      auto ll = [&](LL k) {
        return l[i - 1][k] + sum[k] + max(mxsuf[k + 1], 0ll);
      };
      auto rl = [&](LL k) {
        return r[i - 1][k] + sum[k + 1] + max(0ll, mxsuf[k + 2]);
      };
      auto rr = [&](LL k) {
        return r[i - 1][k] - sum[k - 1] + max(0ll, mxpre[k - 1]);
      };
      auto lr = [&](LL k) {
        return l[i - 1][k] - sum[k - 2] + max(0ll, mxpre[k - 2]);
      };
      LL p2 = m - 1, p1 = m;
      // 对l进行更新
      for (LL j = m - 1; j >= 1; --j) {
        if (ll(j + 1) >= ll(p1))
          p1 = j + 1;
        if (rl(j) >= rl(p2))
          p2 = j;
        l[i][j] = max(ll(p1), rl(p2)) - sum[j - 1];
      }

      // 对r进行更新
      LL p3 = 1, p4 = 2;
      for (LL j = 2; j <= m; ++j) {
        if (rr(j - 1) >= rr(p3))
          p3 = j - 1;
        if (lr(j) >= lr(p4))
          p4 = j;
        r[i][j] = max(rr(p3), lr(p4)) + sum[j];
      }
    }
  }
  LL mv = -1000000000000000000;
  for (LL i = 1; i <= m; ++i) {
    mv = max(max(mv, l[n][i]), r[n][i]);
  }
  cout << mv << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> t;
  while (t--)
    solve();
}
