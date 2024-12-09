
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int MAXN = 1000003;
LL a, b, n;
LL att[MAXN];
LL hel[MAXN];
LL attrel[MAXN];
void solve() {
  cin >> a >> b >> n;
  for (int i = 0; i < n; ++i) {
    cin >> att[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> hel[i];
  }
  for (int i = 0; i < n; ++i) {
    attrel[i] = att[i] * ((hel[i] + a - 1) / a);
  }
  // for (int i = 0; i < n; ++i) {
  // cout << attrel[i] << " ";
  // }
  LL totatt = 0;
  for (int i = 0; i < n; ++i) {
    totatt += attrel[i];
  }
  for (int i = 0; i < n; ++i) {
    if (totatt - attrel[i] >= b)
      continue;
    else {
      // cout << ":" << i;
      int h1 = hel[i];
      int a1 = att[i];
      LL cpb = b - (totatt - attrel[i]);
      LL maxsufcnt = (cpb + a1 - 1) / a1;
      if (h1 - maxsufcnt * a <= 0) {
        cout << "YES" << endl;
        return;
      }
    }
  }
  cout << "NO" << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
}
