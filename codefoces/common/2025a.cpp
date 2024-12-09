#include <bits/stdc++.h>

using namespace std;

void solve() {
  string s1, s2;
  cin >> s1 >> s2;
  int p1 = 0;
  int p2 = 0;
  int cnt = 0;
  if (s1[0] == s2[0])
    cnt++;
  while (p1 < s1.length() && p2 < s2.length()) {
    if (s1[p1] == s2[p2]) {
      cnt++;
      p1++;
      p2++;

    } else {
      break;
    }
  }
  cnt += s1.length() - p1 + s2.length() - p2;
  cout << cnt << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
