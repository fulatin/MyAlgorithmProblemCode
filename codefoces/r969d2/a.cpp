#include <iostream>

using namespace std;

int t;

void solve() {

  int l, r;
  cin >> l >> r;
  if (r - l + 1 < 3) {
    cout << 0 << endl;
    return;
  }

  int odd = 0;
  for (int i = l; i <= r; ++i) {
    if (i % 2 == 1) {
      odd++;
    }
  }
  cout << odd / 2 << endl;
}

int main() {
  cin >> t;
  while (t--) {
    solve();
  }
}
