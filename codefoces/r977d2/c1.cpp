#include <bits/stdc++.h>
#include <cstring>

using namespace std;
const int MAXN = 200002;
int t, n, m, q;
bool ok[MAXN];
int arra[MAXN], arrb[MAXN];
void solve() {
  cin >> n >> m >> q;
  memset(ok, 0, sizeof(ok));
  memset(arra, 0, sizeof(arra));
  memset(arrb, 0, sizeof(arrb));
  for (int i = 1; i <= n; ++i) {
    cin >> arra[i];
  }
  for (int i = 1; i <= m; ++i) {
    cin >> arrb[i];
  }
  int nowpos = 1;
  for (int i = 1; i <= m; ++i) {
    if (ok[arrb[i]]) {
      continue;
    }
    if (arra[nowpos] == arrb[i]) {

      ok[arra[nowpos]] = true;
      nowpos++;
    } else {
      cout << "TIDAK" << endl;
      return;
    }
  }
  cout << "YA" << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin >> t;
  while (t--) {
    solve();
  }
}
