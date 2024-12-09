#include <iostream>

using namespace std;

int t;

void solve() {
  int l, r;
  cin >> l >> r;
  int tar = 2 * (r - l);
  for (int i = 1;; ++i) {
    int val = i * (i - 1);
    if (val <= tar && val + i * 2 > tar) {
      cout << i << endl;
      return;
    }
  }
}

int main() {
  cin >> t;
  while (t--) {
    solve();
  }
}
