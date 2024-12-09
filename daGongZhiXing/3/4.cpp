#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

const int MAXN = 1e5 + 3;
LL as[MAXN], bs[MAXN], cs[MAXN], ds[MAXN], n, m;

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> as[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> bs[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> cs[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> ds[i];
  }
  int pos = 1;
  int conticnt = 0;
  LL score = 0;
  while (m > 0 && pos <= n) {
    int timetake = cs[pos];
    if (timetake > m) {
      m -= timetake;
      pos++;
      continue;
    }
    if (ds[pos]) {
      score += as[pos];
      score += bs[++conticnt];
    } else {
      conticnt = 0;
    }
    pos++;
    m -= timetake;
  }
  cout << score;
}
