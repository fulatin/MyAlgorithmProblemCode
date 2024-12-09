#include <iostream>

using namespace std;

int t;

void solve() {
  int n, one = 0, zero = 0;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    char curr;
    cin >> curr;
    curr == '1' ? one++ : zero++;
  }

  if (one % 4 == 0 && ((one / 4 + 1) - 2) * ((one / 4 + 1) - 2) == zero) {
    cout << "YES" << endl;
    return;
  }
  cout << "NO" << endl;
}

int main() {
  cin >> t;
  while (t--) {
    solve();
  }
}
