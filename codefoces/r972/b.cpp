#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1000000000;

int t, n, q, m;
bitset<MAXN + 1> teacher;

void solve() {
  teacher.reset();
  cin >> n >> m >> q;
  for (int i = 1; i <= m; ++i) {
    int curr;
    cin >> curr;
    teacher[curr] = true;
  }
  int pos;
  cin >> pos;
  int left, right;
  for (left = pos; left > 0 && !teacher[left]; left--) {
  }
  for (right = pos; right <= n && !teacher[right]; right++) {
  }
  if (left == 0) {
    cout << right;
    cout << endl;
    return;
  }
  if (right == 0) {
    cout << left;
    cout << endl;
    return;
  }
  cout << ((right - left) >> 1) << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin >> t;
  while (t--) {
    solve();
  }
}
