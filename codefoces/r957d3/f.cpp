#include <bits/stdc++.h>

using namespace std;
const int MAXN = 100004;
int t;

void solve() {
  int n, x;
  cin >> n >> x;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  int scnt = 1;
  set<int> apart;
  apart.insert(x);
  for (int i = 0; i < n; ++i) {
    if (x % v[i] != 0)
      continue;
    if (apart.size() != 0 && apart.find(v[i]) != apart.end()) {
      apart.clear();
      apart.insert(x / v[i]);
      apart.insert(x);
      scnt++;
    } else {
      set<int> ano(apart);
      for (auto e : ano) {
        if (e % v[i] == 0)
          apart.insert(e / v[i]);
      }
    }
  }
  cout << scnt << endl;
}

int main() {
  // ios::sync_with_stdio(false);
  cin >> t;
  while (t--) {
    solve();
  }
}
