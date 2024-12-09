#include <bits/stdc++.h>
using namespace std;

int t;
typedef unsigned long long ull;
void solve() {
  ull b, c, d;
  cin >> b >> c >> d;
  ull delable = b & c;
  ull addable = (~b) & (~c);
  ull add1 = d - (b & d);
  ull del1 = b - (b & d);
  if (((addable & add1) == add1) && (delable & del1) == del1) {
    cout << (add1 | del1) << endl;
  } else {
    cout << -1 << endl;
  }
}

int main() {
  cin >> t;
  while (t--) {
    solve();
  }
}
