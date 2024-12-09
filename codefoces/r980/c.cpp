#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

struct dt {
  int a;
  int b;
  int mn;
  int mx;
  bool operator<(dt o) {
    if (o.mx != this->mx)
      return o.mx > this->mx;
    return o.mn > this->mn;
  }
};

void solve() {
  int n;
  cin >> n;
  vector<dt> v(n);
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    v[i] = {a, b, max(a, b), min(a, b)};
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; ++i) {
    cout << v[i].a << ' ' << v[i].b << ' ';
  }
  cout << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
