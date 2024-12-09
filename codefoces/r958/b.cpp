#include <bits/stdc++.h>

using namespace std;

int t;

void solve() {
  int n;
  string s;
  cin >> n;
  cin >> s;
  int ocnt = 0, zcnt = 0;
  int prev = 1;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1')
      ocnt++;
    if (s[i] == '0' && prev == 1) {
      zcnt++;
    }
    prev = s[i] - '0';
  }
  if (zcnt >= ocnt)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
}
int main() {
  cin >> t;
  while (t--)
    solve();
  return 0;
}
