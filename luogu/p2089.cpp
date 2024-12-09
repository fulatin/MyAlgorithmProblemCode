#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> ans;
void solve(int t, vector<int> s) {
  if (s.size() > 10)
    return;
  if (t > n) {
    return;
  }
  if (t == n) {
    if (s.size() != 10)
      return;
    ans.push_back(s);
  }

  s.push_back(1);
  solve(t + 1, s);
  s.pop_back();
  s.push_back(2);
  solve(t + 2, s);
  s.pop_back();
  s.push_back(3);
  solve(t + 3, s);
  s.pop_back();
}

int main() {
  cin >> n;
  vector<int> v;
  solve(0, v);
  cout << ans.size() << endl;
  for (auto e : ans) {
    for (auto j : e) {
      cout << j << ' ';
    }
    cout << endl;
  }
  return 0;
}
