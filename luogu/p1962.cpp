
#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long LL;
const int MOD = 1e9 + 7;
int n;
LL mat[101][101];
LL ans[101][101];
LL b;
void mult() {
  LL tmpmat[101][101] = {0};
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        tmpmat[i][j] = (tmpmat[i][j] + (mat[i][k] * mat[k][j]) % MOD) % MOD;
        tmpmat[i][j] %= MOD;
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      mat[i][j] = tmpmat[i][j];
    }
  }
}
void multans() {
  LL tmpmat[101][101] = {0};
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        tmpmat[i][j] = (tmpmat[i][j] + (ans[i][k] * mat[k][j]) % MOD) % MOD;
        tmpmat[i][j] %= MOD;
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      ans[i][j] = tmpmat[i][j];
    }
  }
}
int main() {
  cin >> n;

  b = n;
  n = 2;
  mat[1][1] = 0;
  mat[1][2] = 1;
  mat[2][1] = 1;
  mat[2][2] = 1;
  ans[1][1] = 1;
  ans[2][2] = 1;
  b++;
  while (b > 0) {
    if (b & 1)
      multans();
    mult();
    b /= 2;
  }
  cout << ans[1][1];
  return 0;
}
