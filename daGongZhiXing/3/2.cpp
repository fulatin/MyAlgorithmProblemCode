#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL grid[12][100];

int main() {
  int n, m;
  cin >> n >> m;
  int k;
  cin >> k;
  for (int i = 1; i <= k; ++i) {
    cin >> grid[1][i];
  }
  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j <= i + k - 1; ++j) {
      grid[i][j] = grid[i - 1][j - 1] + grid[i - 1][j];
    }
  }
  cout << grid[n][m];
  return 0;
}
