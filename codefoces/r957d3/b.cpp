#include <bits/stdc++.h>
#include <functional>

using namespace std;

int t, n, k;

void solve() {
  cin >> n >> k;
  vector<int> arr(k);
  for (int i = 0; i < k; ++i) {
    cin >> arr[i];
  }
  sort(arr.begin(), arr.end(), greater<>());
  int m = arr[0];
  int ans = 0;
  for (int i = 1; i < k; ++i) {
    int pre = arr[i];
    ans = ans + pre + pre - 1;
  }
  cout << ans << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
