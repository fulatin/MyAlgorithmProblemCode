#include <iostream>
using namespace std;

int t;

void solve() {
  int one, two;
  cin >> one >> two;
  if (one % 2) {
    cout << "NO" << endl;
  } else if (two % 2 && one < 2) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
}

int main() {
  cin >> t;
  while (t--) {
    solve();
  }
}
