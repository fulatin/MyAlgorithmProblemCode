#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int t;
void solve() {
  int n, d, k;
  cin >> n >> d >> k;
  vector<int> start(n + 1);
  vector<int> end(n + 2);
  for (int i = 1; i <= k; ++i) {
    int l, r;
    cin >> l >> r;
    start[l]++;
    end[r + 1]++;
  }
  vector<int> startacc(n + 1), endacc(n + 1);
  for (int i = 1; i <= n; ++i) {
    startacc[i] = start[i] + startacc[i - 1];
    endacc[i] = end[i] + endacc[i - 1];
  }
  // for (auto e : startacc)
  // cout << e << ' ';
  // cout << endl;

  // for (auto e : endacc)
  // cout << e << ' ';

  int bro = -1;
  int mother = 1000000000;
  int brod = 1;
  int motherd = 1;
  for (int i = d; i <= n; ++i) {
    int curr = startacc[i] - endacc[i - d + 1];
    // cout << "our " << curr << endl;
    if (curr > bro) {
      // cout << "enter bor" << endl;
      bro = curr, brod = i - d + 1;
    }
    if (curr < mother) {
      // cout << "enter mom;";
      // cout << "i is" << i << endl;
      mother = curr, motherd = i - d + 1;
    }
  }
  cout << brod << ' ' << motherd << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--)
    solve();
}
