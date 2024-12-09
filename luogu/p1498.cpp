#include <bits/stdc++.h>

using namespace std;

const int MAXN = 4 * 512 + 3;
char g[MAXN][MAXN];
char base[2][5] = {" /\\ ", "/__\\"};
void build(int l, int r, int t, int d) {
  if (r - l == 3) {
    for (int i = 0; i <= 1; ++i) {
      for (int j = 0; j <= 3; ++j) {
        g[t + i][l + j] = base[i][j];
      }
    }
  } else {
    build(l, (l + r) / 2, (t + d) / 2 + 1, d);
    build((l + r) / 2 + 1, r, (t + d) / 2 + 1, d);
    build((((l + r) / 2) + l) / 2 + 1, ((l + r) / 2 + r) / 2, t, (t + d) / 2);
  }
}
int main() {
  int n;
  cin >> n;
  int range = 1 << (n - 1);
  build(1, range * 4, 1, range * 2);
  for (int i = 1; i <= range * 2; ++i) {
    for (int j = 1; j <= range * 4; ++j) {
      cout << (g[i][j] == 0 ? ' ' : g[i][j]);
    }
    cout << endl;
  }
}
