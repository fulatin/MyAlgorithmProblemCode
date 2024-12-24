#include <iostream>

using namespace std;

void solve() {
  int n, d;
  cin >> n >> d;
  cout << 1 << ' ';
  if (d == 3 || d == 9 || d == 6 || n >= 3) {
    cout << 3 << ' ';
  }
  if (d == 5) {
    cout << 5 << ' ';
  }
  if (d == 7 || n >= 3) {
    cout << 7 << ' ';
  }
  if (d == 9 || n >= 6 || ((d == 3 || d == 6) && n >= 3)) {
    cout << 9 << ' ';
  }
  cout << '\n';
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
}
