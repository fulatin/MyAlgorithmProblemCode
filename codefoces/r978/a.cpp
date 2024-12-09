#include <bits/stdc++.h>

using namespace std;
int t;
void solve() {
  int n, r;
  cin >> n >> r;
  int rest = 0;
  int happycnt = 0;
  for (int i = 1; i <= n; ++i) {
    int curr;
    cin >> curr;
    if (curr % 2)
      rest++;
    happycnt += curr - curr % 2;
  }
  r -= happycnt / 2;
  if (rest <= r) {
    happycnt += rest;
  } else {
    r = r - (rest - r);
    happycnt += r;
  }
  cout << happycnt << endl;
}
int main() {
  cin >> t;
  while (t--)
    solve();
}
