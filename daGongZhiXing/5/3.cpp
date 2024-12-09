#include <bits/stdc++.h>

using namespace std;

int wdmap[302][11];
int helparr[11];
int main() {
  string zk;
  int m;
  cin >> zk;
  cin >> m;
  for (int i = zk.length() - 1; i >= 0; --i) {
    char c = zk[i];
    for (int j = 0; j <= 9; ++j) {
      wdmap[i + 1][j] = helparr[j];
    }
    helparr[c - '0'] = i + 1;
  }
  for (int i = 0; i <= 9; ++i) {
    wdmap[0][i] = helparr[i];
  }
  zk = 'x' + zk;
  string lc, rc;
  cin >> lc >> rc;
  int pos = 0;
  for (int i = 0; i < m; ++i) {
    int l = lc[i] - '0';
    int r = rc[i] - '0';
    int mn = 0;
    for (int j = l; j <= r; ++j) {

      // cout << pos << ' ' << j << ' ' << wdmap[pos][j] << endl;
      if (wdmap[pos][j] == 0) {
        cout << "YES";
        return 0;
      }
      mn = max(mn, wdmap[pos][j]);
    }
    pos = mn;
  }
  cout << "NO" << endl;
  return 0;
}
