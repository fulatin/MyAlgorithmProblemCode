#include <bits/stdc++.h>
using namespace std;

int t;

void solve() {
  int n, k;
  cin >> n >> k;
  int cnt = 0;
  while (n > 0) {
    if (n % k == 0) {
      n /= k;
    } else {
      cnt += n % k;
      n /= k;
    }
  }
  cout << cnt << endl;
}

int main() {
  cin >> t;
  while (t--) {
    solve();
  }
}
