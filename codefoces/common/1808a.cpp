#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1000005;
int mem[MAXN];
int n, t;
int luckv(int a) {
  int minv = 10000000;
  int maxv = -1;
  while (a > 0) {
    minv = min(a % 10, minv);
    maxv = max(a % 10, maxv);
    a /= 10;
  }
  return maxv - minv;
}

void solve() {
  int l, r;
  cin >> l >> r;
  int mpos = l;
  int mv = -1;
  for (int i = l; i <= r; ++i) {
    if (mv == 9)
      break;
    int curr;
    if (mem[i] != -1) {
      curr = mem[i];
    } else {
      curr = luckv(i);
      mem[i] = curr;
    }
    if (curr > mv) {
      mpos = i;
      mv = curr;
    }
  }
  cout << mpos << endl;
}

int main() {
  ios::sync_with_stdio(false);
  memset(mem, -1, sizeof(mem));
  cin >> t;
  while (t--) {
    solve();
  }
}
