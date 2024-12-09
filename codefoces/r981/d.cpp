#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100003;
int t, n;
int arr[MAXN];
set<int> sums;

void solve() {
  cin >> n;
  sums.clear();
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
  }
  int sum = 0;
  int ans = 0;
  sums.insert(0);
  for (int i = 1; i <= n; ++i) {
    sum += arr[i];
    if (sums.find(sum) != sums.end()) {
      ans++;
      sums.clear();
      sums.insert(sum);

    } else {
      sums.insert(sum);
    }
  }
  cout << ans << endl;
}
int main() {
  cin >> t;
  while (t--)
    solve();
}
