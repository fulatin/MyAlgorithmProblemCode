#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  int i;
  int pos = 0;
  for (i = 1; abs(pos) <= n; ++i) {
    pos += (2 * i - 1) * ((i % 2 == 0) ? -1 : 1);
  }
  cout << (((i - 1) % 2) ? "Sakurako" : "Kosuke") << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
