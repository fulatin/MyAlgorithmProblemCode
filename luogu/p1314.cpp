#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN = 2 * 1e5 + 4;

int n, m;
LL s;
int w[MAXN], v[MAXN];

vector<pair<int, int>> frag;

LL check(int x) {
  vector<int> overx(n + 1);
  vector<LL> overxv(n + 1);
  for (int i = 1; i <= n; ++i) {
    if (w[i] >= x) {
      overx[i]++;
      overxv[i] += v[i];
    }
  }
  // cout << x << endl;
  // for (int i = 1; i <= n; ++i) {
  //   cout << overx[i] << ' ';
  // }
  //
  // cout << endl;
  // for (int i = 1; i <= n; ++i) {
  //   cout << overxv[i] << ' ';
  // }
  // cout << endl;
  for (int i = 1; i <= n; ++i) {
    overx[i] += overx[i - 1];
    overxv[i] += overxv[i - 1];
  }
  // for (int i = 1; i <= n; ++i) {
  //   cout << overx[i] << ' ';
  // }
  //
  // cout << endl;
  // for (int i = 1; i <= n; ++i) {
  //   cout << overxv[i] << ' ';
  // }
  // cout << endl;
  LL tot = 0;
  for (int i = 1; i <= m; ++i) {
    int l = frag[i].first;
    int r = frag[i].second;
    tot += (overx[r] - overx[l - 1]) * (overxv[r] - overxv[l - 1]);
  }
  // printf("%d %lld\n", x, tot);
  return tot;
}
int main() {
  cin >> n >> m >> s;
  int maxw = -1;
  for (int i = 1; i <= n; ++i) {
    cin >> w[i] >> v[i];
    maxw = max(maxw, w[i]);
  }
  frag.resize(m + 1);
  for (int i = 1; i <= m; ++i) {
    cin >> frag[i].first >> frag[i].second;
  }
  int l = 0, r = maxw;
  while (r - l > 1) {
    int mid = (l + r) >> 1;
    if (check(mid) == s) {
      l = r = mid;
    } else if (check(mid) > s) {
      l = mid;
    } else {
      r = mid;
    }
    // cout << l << endl;
  }
  // set<pair<int, int>> checks;
  // set<int> have;
  // for (int i = 1; i < maxw; ++i) {
  //   if (have.find(check(i)) == have.end()) {
  //     checks.insert({i, check(i)});
  //     have.insert(check(i));
  //   }
  // }
  // for (auto e : checks) {
  //   cout << e.first << ' ' << e.second << ' ';
  // }
  //
  // cout << endl;
  // cout << endl;
  cout << (abs(check(l) - s) < abs((check(r) - s)) ? abs(s - check(l))
                                                   : abs(check(r) - s));
  return 0;
}
