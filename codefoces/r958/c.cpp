#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long Ull;

void solve() {
  Ull x;
  cin >> x;
  vector<int> poscnt;
  int cnt = 0;
  Ull cpx = x;
  while (cpx > 0) {

    if (cpx % 2)
      poscnt.push_back(cnt);
    cnt++;
    cpx /= 2;
  }
  vector<Ull> ans;
  ans.push_back(x);
  cpx = x;
  for (int i = 0; i < poscnt.size(); ++i) {
    if (cpx - ((1Ull) << poscnt[i]) == 0)
      continue;
    ans.push_back(cpx - ((1Ull) << poscnt[i]));
  }
  cout << ans.size() << endl;
  for (int i = ans.size() - 1; i >= 0; i--) {
    cout << ans[i] << ' ';
  }
  cout << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
