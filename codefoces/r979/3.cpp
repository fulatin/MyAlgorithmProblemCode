
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  if (s[0] == '1' || s[n - 1] == '1') {
    cout << "YES" << endl;
    return;
  } else {
    int ocnt = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '0')
        ocnt = 0;
      else
        ocnt++;
      if (ocnt == 2) {
        cout << "YES" << endl;
        return;
      }
    }
  }
  cout << "NO" << endl;
  return;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
