
#include <bits/stdc++.h>

typedef long long LL;

using namespace std;

void solve() {
  int n;
  cin >> n;
  string s, r;
  cin >> s >> r;
  int cnt1 = 0, cnt0 = 0;
  for (int i = 0; i < n; ++i)
    if (s[i] == '0')
      cnt0++;
    else
      cnt1++;
  for (int i = 0; i < n - 1; ++i) {
    if (cnt0 == 0 || cnt1 == 0) {
      cout << "NO" << endl;
      return;
    }
    if (r[i] == '0')
      cnt1--;
    else
      cnt0--;
  }
  cout << "YES" << endl;
  return;
}

int main() {
  int T;
  cin >> T;
  while (T--)
    solve();
}
