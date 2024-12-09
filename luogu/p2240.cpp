#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

struct pile {
  int m;
  int v;
  bool operator<(struct pile o) { return this->v * o.m > this->m * o.v; }
} p[102];
int n, t;
int main() {
  cin >> n >> t;
  for (int i = 1; i <= n; ++i) {
    int m, v;
    cin >> m >> v;
    p[i].m = m;
    p[i].v = v;
  }
  sort(p + 1, p + n + 1);
  int cnt = 0;
  int pos = 1;
  double ans = 0;
  while (pos <= n) {
    if (cnt + p[pos].m <= t) {
      cnt += p[pos].m;
      ans += p[pos].v;
    } else {
      ans += (t - cnt) * ((double)p[pos].v / p[pos].m);
      break;
    }
    pos++;
  }
  cout.setf(ios::fixed);
  cout << setprecision(2) << ans;
}
