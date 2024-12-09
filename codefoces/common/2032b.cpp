#include <bits/stdc++.h>

using namespace std;

int t, n, k;

void solve() {
  cin >> n >> k;
  if (n == 1) {
    cout << 1 << endl << 1 << endl;
    return;
  }
  if (((k - 1) / 2) % 2) {
    if (k == 1 || k == n) {
      cout << -1 << endl;
      return;
    }
    cout << 3 << endl;
    cout << 1 << ' ' << k << ' ' << k + 1 << endl;
    return;
  } else {
  }
}
int main() {
  cin >> t;
  while (t--)
    solve();
}
