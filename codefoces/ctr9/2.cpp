
#include <bits/stdc++.h>

using namespace std;

void solve() {
  string s;

  cin >> s;
  int len = s.size();
  for (int i = 0; i < len - 1; ++i) {
    if (s[i] == s[i + 1]) {
      cout << s[i] << s[i] << endl;
      return;
    }
  }
  for (int i = 0; i < len - 2; ++i) {
    if (s[i] != s[i + 1] && s[i + 1] != s[i + 2] && s[i] != s[i + 2]) {
      cout << s[i] << s[i + 1] << s[i + 2] << endl;
      return;
    }
  }
  cout << -1 << endl;
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--)
    solve();
  return 0;
}
