#include <bits/stdc++.h>

using namespace std;

int n, arr[200002];
int sum[200002];
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
  }
  for (int i = 1; i <= n; ++i) {
    sum[i] = arr[i] + sum[i - 1];
  }
  int mn = 0;
  int ans = -0x6fffffff;
  for (int i = 1; i <= n; ++i) {
    ans = max(ans, sum[i] - mn);
    mn = min(sum[i], mn);
  }
  cout << ans;
  return 0;
}
