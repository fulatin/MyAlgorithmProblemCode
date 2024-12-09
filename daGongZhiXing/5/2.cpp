#include <bits/stdc++.h>

using namespace std;

string tar = "Wuli";

long long a, b, c, d, e;
void solve() {
  string tp;
  cin >> tp;
  cin >> a >> b >> c >> d >> e;
  if (tp == tar) {
    cout << d * 1000000ll -
                b * (10000ll + (c >= 100 ? 100 : c) * (2 * c + 100)) * (100 - e)
         << endl;
  } else {
    cout << d * 1000000ll - b * (100 - e) * 10000 << endl;
  }
}
int main() {
  int T;
  cin >> T;
  while (T--)
    solve();
}
