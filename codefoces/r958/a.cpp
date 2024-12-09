#include <bits/stdc++.h>

using namespace std;
int t;

void solve() {
  int x, k;
  cin >> x >> k;

  cout << (x + k - 3) / (k - 1) << endl;
}
int main() {
  cin >> t;
  while (t--)
    solve();
}
