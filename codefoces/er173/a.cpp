#include <iostream>
#include <vector>

using namespace std;
void solve() {
  long long x;
  cin >> x;
  int has = 1;
  while (x > 3) {
    has *= 2;
    x >>= 2;
  }
  cout << has << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
}
