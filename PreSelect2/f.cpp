#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, x;
  cin >> n >> x;
  int sum = 0;
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    int curr;
    cin >> curr;
    if (x == curr)
      cnt++;
    sum += curr;
  }

  if (cnt == n) {
    cout << 0 << endl;
    return;
  }
  if (sum == n * x || cnt >= 1) {
    cout << 1 << endl;
    return;
  }
  cout << 2 << endl;
  return;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
}
