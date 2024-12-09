#include <bits/stdc++.h>

using namespace std;
int t;

void solve() {
  int a, b;
  cin >> a >> b;
  if (a == 0 || b == 0) {
    cout << 0 << endl;
    return;
  }
  if (a > 0 && b > 0) {
    int m = abs(a - b);
    m = min(a, min(m, b));
    cout << m;
    return;
  }
  int g = gcd(a, b);
}

int main() {
  ios::sync_with_stdio(false);
  cin >> t;
  while (t--) {
    solve();
  }
}
