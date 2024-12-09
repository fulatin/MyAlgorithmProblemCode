#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200002;

int dju[MAXN];
int n, m, t;

int fa(int p) {
  if (dju[p] == 0)
    return p;
  int f = fa(dju[p]);
  dju[p] = f;
  return f;
}

void setfa(int p, int f) { dju[p] = fa(f); }

void solve() {
  cin >> n >> m;
  memset(dju, 0, (n + 1) * sizeof(int));
  while (m--) {
    int a, d, k;
    cin >> a >> d >> k;
    for (int i = 0; i < k; ++i) {
      setfa(a + (i + 1) * d, a + i * d);
    }
  }
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    if (dju[i] == 0)
      cnt++;
  }
  cout << cnt << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--)
    solve();
}
