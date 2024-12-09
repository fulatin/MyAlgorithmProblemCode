#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
typedef long long ll;
typedef double db;
typedef pair<int, int> P;
#define fi first
#define se second
#define pb push_back
#define dbg(x) cerr << (#x) << ":" << x << " ";
#define dbg2(x) cerr << (#x) << ":" << x << endl;
#define SZ(a) (int)(a.size())
#define sci(a) scanf("%d", &(a))
#define pt(a) printf("%d", a);
#define pte(a) printf("%d\n", a)
#define ptlle(a) printf("%lld\n", a)
#define debug(...) fprintf(stderr, __VA_ARGS__)
const int N = 105, M = 1e4 + 10;
const ll INF = 1e15;
int t, n, m;
ll sol() {
  sci(n), sci(m);
  vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
  vector<vector<ll>> f(n + 1, vector<ll>(m + 2, -INF));
  vector<vector<ll>> g(n + 1, vector<ll>(m + 2, -INF));
  vector<ll> pre(m + 2, -INF), suf(m + 2, -INF), sum(m + 2, 0);
  ll ans = -INF;
  rep(i, 1, n) {
    pre[0] = suf[m + 1] = -INF;
    rep(j, 1, m) {
      sci(a[i][j]);
      sum[j] = sum[j - 1] + a[i][j];
    }
    rep(j, 1, m) { pre[j] = max(pre[j - 1], sum[m] - sum[j - 1]); }
    per(j, m, 1) { suf[j] = max(suf[j + 1], sum[j]); }
    auto premax = [&](int j) {
      if (j < 1)
        return 0ll;
      return pre[j] - (sum[m] - sum[j]);
    };
    auto sufmax = [&](int j) {
      if (j > m)
        return 0ll;
      return suf[j] - sum[j - 1];
    };
    if (i == 1) {
      rep(j, 1, m) {
        f[i][j] = sufmax(j);
        g[i][j] = premax(j);
      }
    } else {
      auto f1 = [&](int k) {
        return f[i - 1][k] + sum[k] + max(0ll, sufmax(k + 1));
      };
      auto f2 = [&](int k) {
        return f[i - 1][k] - sum[k - 2] + max(0ll, premax(k - 2));
      };
      auto g1 = [&](int k) {
        return g[i - 1][k] - sum[k - 1] + max(0ll, premax(k - 1));
      };
      auto g2 = [&](int k) {
        return g[i - 1][k] + sum[k + 1] + max(0ll, sufmax(k + 2));
      };
      int p1 = m, p2 = m - 1;
      per(j, m - 1, 1) {
        if (f1(j + 1) > f1(p1))
          p1 = j + 1;
        if (g2(j) > g2(p2))
          p2 = j;
        f[i][j] = max(f1(p1), g2(p2)) - sum[j - 1];
      }
      int p3 = 1, p4 = 2;
      rep(j, 2, m) {
        if (g1(j - 1) > g1(p3))
          p3 = j - 1;
        if (f2(j) > f2(p4))
          p4 = j;
        g[i][j] = max(g1(p3), f2(p4)) + sum[j];
      }
    }
    // rep(j,1,m){
    //     printf("i:%d j:%d f:%lld g:%lld\n",i,j,f[i][j],g[i][j]);
    // }
  }
  rep(j, 1, m) {
    ans = max(ans, f[n][j]);
    ans = max(ans, g[n][j]);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cout << f[i][j] << " ";
    }
    cout << endl;
  }
  return ans;
}
int main() {
  sci(t);
  while (t--) {
    ptlle(sol());
  }
  return 0;
}
/*
f[i][j]表示i行j列作为左端点必取的最大和
g[i][j]表示i行j列作为右端点必取的最大和
f[i][j]=max(k从j+1到m f[i-1][k]+sum[j,k]+sufmax[k+1:m]) sum[k]-sum[j-1] (f1)
g[i][j]=max(k从1到j-1 g[i-1][k]+sum[k,j]+premax[1:k-1]) sum[j]-sum[k-1] (g1)
f[i][j]=max(k从j到m-1 g[i-1][k]+sum[j,k+1]+sufmax[k+2:m]) sum[k+1]-sum[j-1] (g2)
g[i][j]=max(k从2到j f[i-1][k]+sum[k-1,j]+premax[1:k-2]) sum[j]-sum[k-2] (f2)
*/
