#include <algorithm>
#include <bits/stdc++.h>
#include <cstring>

using namespace std;

int t, n, d, k;

int harr[100000 + 2];
void solve() {
  memset(harr, 0, sizeof(harr));
  cin >> n >> d >> k;
  for (int i = 0; i < k; ++i) {
    int l, r;
    cin >> l >> r;
    harr[l]++;
  }
  int minv = 0x7fffffff;
  int minpos = 1;
  int maxv = -1;
  int maxpos = 1;

  for (int i = 1; i <= n - d + 1; ++i) {
    int tmpmax = -1;
    for (int j = i; j <= i + d - 1; ++j) {
      if (harr[j] > tmpmax) {
        tmpmax = harr[j];
      }
    }
    if (tmpmax > maxv) {
      maxv = tmpmax;
      maxpos = i;
    }
    if (tmpmax < minv) {
      minv = tmpmax;
      minpos = i;
    }
  }
  cout << maxpos << ' ' << minpos << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin >> t;
  while (t--) {
    solve();
  }
}
