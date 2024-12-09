
#include <bits/stdc++.h>
#include <cstring>

using namespace std;

const int MAXN = 2e5 + 2;
int ff(int x, vector<set<int>> &s) { return *s[x].cbegin(); }

void solve() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> a(n + 2);
  vector<int> b(m + 1);
  vector<set<int>> idx(n + 2);
  map<int, int> apos;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    apos[a[i]] = i;
  }
  a[0] = 0;
  apos[0] = 0;
  apos[n + 1] = n + 1;
  a[n + 1] = n + 1;
  for (int i = 1; i <= n + 1; ++i) {
    idx[i].insert(MAXN);
  }
  for (int i = 1; i <= m; ++i) {
    int t;
    cin >> t;
    b[i] = t;
    idx[t].insert(i);
  }

  int f = 0;
  idx[0].insert(0);
  for (int i = 1; i < n; ++i) {
    if (ff(a[i], idx) > ff(a[i + 1], idx))
      f++;
  }
  if (f == 0)
    cout << "YA" << endl;
  else
    cout << "TIDAK" << endl;
  while (q--) {
    int s, t;
    cin >> s >> t;
    if (ff(b[s], idx) == s) {
      if (ff(a[apos[b[s]] - 1], idx) > ff(b[s], idx))
        f--;
      if (ff(a[apos[b[s]] + 1], idx) < ff(b[s], idx))
        f--;
      idx[b[s]].erase(s);
      if (ff(a[apos[b[s]] - 1], idx) > ff(b[s], idx))
        f++;
      if (ff(a[apos[b[s]] + 1], idx) < ff(b[s], idx))
        f++;

    } else
      idx[b[s]].erase(s);

    if (ff(t, idx) > s) {
      if (ff(a[apos[t] - 1], idx) > ff(t, idx))
        f--;

      if (ff(a[apos[t] + 1], idx) < ff(t, idx))
        f--;
      idx[t].insert(s);
      if (ff(a[apos[t] - 1], idx) > ff(t, idx))
        f++;

      if (ff(a[apos[t] + 1], idx) < ff(t, idx))
        f++;

    } else
      idx[t].insert(s);
    b[s] = t;
    if (f == 0)
      cout << "YA" << endl;
    else
      cout << "TIDAK" << endl;
  }
}
int main() {
  int t;
  ios::sync_with_stdio(false);
  cin >> t;
  while (t--) {
    solve();
  }
}
