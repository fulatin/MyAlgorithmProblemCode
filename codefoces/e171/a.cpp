#include <bits/stdc++.h>

using namespace std;

int t, x, y, k;
void solve() {
  cin >> x >> y >> k;
  int mn = min(x, y);
  printf("0 0 %d %d\n", mn, mn);
  printf("%d 0 0 %d\n", mn, mn);
}
int main() {
  cin >> t;
  while (t--)
    solve();
  return 0;
}
