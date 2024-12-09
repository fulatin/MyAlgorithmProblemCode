
#include <bits/stdc++.h>
#include <functional>

using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  sort(v.rbegin(), v.rend());
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0) {
      if (v[i] % 2 == 0) {
        ans += v[i];
      }
    } else {
      if (v[i] % 2 == 1) {
        ans -= v[i];
      }
    }
  }
  if (ans == 0)
    cout << "Tie" << endl;
  else if (ans > 0)
    cout << "Alice" << endl;
  else
    cout << "Bob" << endl;
  return;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
}
