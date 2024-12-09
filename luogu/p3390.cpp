#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
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
        tmpmat[i][j] = (tmpmat[i][j] + mat[i][k] * mat[k][j]) % MOD;
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
        tmpmat[i][j] = (tmpmat[i][j] + ans[i][k] * mat[k][j]) % MOD;
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
  cin >> b;
  for (int i = 1; i <= n; ++i) {
    ans[i][i] = 1;
    for (int j = 1; j <= n; ++j) {
      cin >> mat[i][j];
    }
  }
  while (b > 0) {
    if (b & 1)
      multans();
    mult();
    b /= 2;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cout << ans[i][j] << ' ';
    }
    cout << endl;
  }
  return 0;
}
