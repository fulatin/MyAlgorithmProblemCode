#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  int cnt1 = 0, cnt0 = 0;
  for (int i = 1; i <= n * 2; ++i) {
    int curr;
    cin >> curr;
    if (curr == 1)
      cnt1++;
    else
      cnt0++;
  }
  cout << (cnt1 % 2 + cnt0 % 2) / 2 << ' ' << min(cnt1, cnt0) << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
