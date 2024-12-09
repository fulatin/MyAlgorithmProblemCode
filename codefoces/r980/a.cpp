#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

void solve() {
  LL a, b;
  cin >> a >> b;
  LL x = b - a;
  if (a >= b)
    cout << a << endl;
  else if (b - a <= 0 || x >= a)
    cout << 0 << endl;
  else
    cout << a - x << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
}
