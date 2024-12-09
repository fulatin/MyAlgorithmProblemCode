#include <bits/stdc++.h>

using namespace std;

int t;
void solve() {
  vector<int> v(4);
  for (int i = 1; i <= 3; ++i) {
    cin >> v[i];
  }
  for (int i = 1; i <= 5; ++i) {
    sort(v.begin() + 1, v.begin() + 4);
    v[1]++;
  }
  int ans = 1;
  for (int i = 1; i <= 3; ++i) {
    ans *= v[i];
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin >> t;
  while (t--)
    solve();
  return 0;
}
