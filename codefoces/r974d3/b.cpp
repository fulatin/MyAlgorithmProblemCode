#include <bits/stdc++.h>

using namespace std;
int t;

void solve() {
  int n, k;
  cin >> n >> k;
  int lo = n - k + 1 > 0 ? n - k + 1 : 1;
  if ((lo + n) * (n - lo + 1) % 4 == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

int main() {
  cin >> t;
  while (t--) {
    solve();
  }
}
