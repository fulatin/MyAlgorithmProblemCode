#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

void solve() {
  LL n, k;
  cin >> n >> k;
  vector<LL> arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  sort(arr.begin(), arr.end());
  LL sum = 0;
  int i;
  for (i = 0; i < n; ++i) {
    sum += arr[i];
    if (sum + arr[i] * (n - i - 1) >= k)
      break;
  }
  cout << k + i << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
}
