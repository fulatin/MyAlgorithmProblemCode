#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL n, m, k;

int main() {
  cin >> n >> m >> k;
  vector<LL> vs(n);
  for (int i = 0; i < n; ++i) {
    cin >> vs[i];
  }
  sort(vs.begin(), vs.end());
  LL dcnt = (k + m - 1) / m;
  LL dm = k / dcnt;
  LL rst = k - dm * dcnt;
  LL ans = 0;
  ans += m * m;
  for (int i = 1; i <= rst; ++i) {
    ans -= (dm + 1) * (dm + 1);
  }
  for (int i = 1; i <= dcnt - rst; i++) {
    ans -= dm * dm;
  }
  ans /= 2;

  for (int i = 1; i <= rst; ++i) {
  }
}
