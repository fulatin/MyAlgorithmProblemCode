#include <iostream>

using namespace std;
const int MAXN = 2 * 1e3 + 4;

typedef long long LL;

int n;
LL x[MAXN], y[MAXN], z[MAXN], r, h;
int dju[MAXN];

int fa(int x) {
  if (dju[x] == x)
    return x;
  else
    return dju[x] = fa(dju[x]);
}

void addfa(int u, int v) {
  int ufa = fa(u);
  int vfa = fa(v);
  if (ufa == vfa)
    return;
  dju[vfa] = ufa;
}

void solve() {
  cin >> n >> h >> r;
  dju[0] = 0;
  dju[n + 1] = n + 1;
  for (int i = 1; i <= n; ++i) {
    dju[i] = i;
    cin >> x[i] >> y[i] >> z[i];
    if (z[i] <= r)
      addfa(0, i);
    if (z[i] + r >= h)
      addfa(n + 1, i);
    for (int j = 1; j < i; ++j) {
      if ((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) +
              (z[i] - z[j]) * (z[i] - z[j]) <=
          4 * r * r)
        addfa(j, i);
    }
    for (int k = 0; k <= n + 1; ++k) {
      cout << dju[k] << ' ';
    }
    cout << endl;
  }
  if (dju[0] == dju[n + 1])
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
int main() {
  int T;
  cin >> T;
  while (T--)
    solve();
  return 0;
}
