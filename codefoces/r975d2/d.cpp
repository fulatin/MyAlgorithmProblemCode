#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200000 + 2;
int t, n;
int arr[MAXN];

void solve() {
  cin >> n;
  int l = -1;
  int r = n + 1;
  for (int i = 1; i <= n; ++i) {
    int curr;
    cin >> curr;
    arr[i] = curr;
    l = max(l, i - curr + 1);
    r = min(r, i + curr - 1);
  }
  if (l > r) {
    cout << 0;
    return;
  }
  int flg = true;
  for (int i = 1; i <= n; ++i) {
    if (i < max(i - l + 1, r - i + 1))
      flg = false;
  }
  cout << (flg ? (min(n, r) - max(1, l) + 1) : 0);
}

int main() {
  ios::sync_with_stdio(false);
  cin >> t;
  while (t--) {
    solve();
  }
}
